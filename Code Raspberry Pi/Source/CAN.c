/*
 * ÇAN_BUS.h
 * @author  Anthony Ducharme, Adapted by Jérémie Roy
 * @date    2025-12-01
 * Driver pour CAN a partir du MCP2515
 */
#define _GNU_SOURCE
#include "../Include/CAN.h"
#include "MCP2515.c"
#include "../Include/SPI.h"
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

/****************************************************** Send Can Frame *************************************************************/
void SendCANFrame(uint16_t id, uint8_t *data, uint8_t length)
{
    if (length > 8)
        length = 8;

    // Conversion ID standard (11 bits) en SIDH / SIDL
    uint8_t sidh = (id >> 3) & 0xFF; // bits 10..3
    uint8_t sidl = (id & 0x07) << 5; // bits 2..0 dans bits 7..5
    uint8_t dlc = length & 0x0F;     // max 8 octets de données

    // Écrire SIDH / SIDL / DLC dans TXB0
    MCP2515_Write(MCP_TXB0SIDH, &sidh, 1);
    MCP2515_Write(MCP_TXB0SIDL, &sidl, 1);
    MCP2515_Write(MCP_TXB0DLC, &dlc, 1);

    // Charger les données
    MCP2515_LoadTxBuffer(0, data, length, 0);

    // Demande d'envoi via RTS
    MCP2515_RTS(0);
    printf("trame send");
}
/***********************************************************************************************************************************/

/**************************************************** Receive Can Frame ************************************************************/
int ReadCANFrame(uint16_t *id, uint8_t *data, uint8_t *length)
{
    // Lire le statut RX (RXnIF)
    uint8_t status = MCP2515_RXSTATUS();

    if (status & 0x40) // RXB0 a reçu une trame (RX0IF)
    {
        uint8_t sidh, sidl, dlc;

        // Lire l'identifiant standard
        MCP2515_Read(MCP_RXB0SIDH, &sidh, 1);
        MCP2515_Read(MCP_RXB0SIDL, &sidl, 1);
        *id = ((uint16_t)sidh << 3) | (sidl >> 5);

        // Lire DLC
        MCP2515_Read(MCP_RXB0DLC, &dlc, 1);
        *length = dlc & 0x0F;

        // Lire les données
        for (uint8_t i = 0; i < *length; i++)
        {
            MCP2515_Read(MCP_RXB0D0 + i, &data[i], 1);
        }

        // Effacer le flag RX0IF
        MCP2515_BitModify(MCP_CANINTF, 0x01, 0x00);
        return 1;
    }
    else if (status & 0x80) // RXB1 a reçu une trame (RX1IF)
    {
        uint8_t sidh, sidl, dlc;

        // Lire l'identifiant standard
        MCP2515_Read(MCP_RXB1SIDH, &sidh, 1);
        MCP2515_Read(MCP_RXB1SIDL, &sidl, 1);
        *id = ((uint16_t)sidh << 3) | (sidl >> 5);

        // Lire DLC
        MCP2515_Read(MCP_RXB1DLC, &dlc, 1);
        *length = dlc & 0x0F;

        // Lire les données
        for (uint8_t i = 0; i < *length; i++)
        {
            MCP2515_Read(MCP_RXB1D0 + i, &data[i], 1);
        }

        // Effacer le flag RX1IF
        MCP2515_BitModify(MCP_CANINTF, 0x02, 0x00);
        return 1;
    }

    return 0; // Aucune trame reçue
}
/***********************************************************************************************************************************/

/***************************************************Send Can Frame with weight******************************************************/
void SendCanFrame_Float(uint16_t id, float value)
{
    uint8_t data[8];
    int entier = (int)value;                     // ex : 39
    int decimal = (int)((value - entier) * 100); // ex : 65

    // Extraction des chiffres → caractères avec '0'
    data[0] = (entier / 10) + '0';  // '3'
    data[1] = (entier % 10) + '0';  // '9'
    data[2] = '.';                  // '.'
    data[3] = (decimal / 10) + '0'; // '6'
    data[4] = (decimal % 10) + '0'; // '5'

    // Envoi des 5 caractères
    SendCANFrame(id, data, 5);

    printf("Float %.2f envoyé CAN : '%c' '%c' '%c' '%c' '%c'\n",
           value,
           data[0], data[1], data[2], data[3], data[4]);
}
/***********************************************************************************************************************************/

/****************************************************Thread du RX*******************************************************************/
void *CAN_Thread_RX(void *arg)
{
    (void)arg;
    uint16_t id;
    uint8_t data[8];
    uint8_t len;

    while (1)
    {
        if (ReadCANFrame(&id, data, &len))
        {
            if (len > 8)
                len = 8;
            printf("[CAN RX] ID = 0x%03X Data = ", id);
            for (int i = 0; i < len; i++)
                printf("%02X ", data[i]);
            printf("\n");
            /*if ((CAN_id != id) | (CAN_Buffer != data) | (CAN_Length != len))
             {
                 CAN_id = id;
                 for (int i = 0; i < 8; i++)
                 {
                     CAN_Buffer[i] = data[i];
                 }
                 CAN_Length = len;
                 CAN_Read_Flag = 1;
             }*/
        }
        usleep(1000); // Evite 100% CPU
    }
    return NULL;
}
/***********************************************************************************************************************************/