/*
 * mcp2515.h
 * @author  Anthony Ducharme
 * @date    2025-12-01
 * Driver pour contrôleur CAN MCP2515 via SPI
 */
#define _GNU_SOURCE
#include "../Include/MCP2515.h"
#include "SPI.c"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/********************************************************* MCP RESET ****************************************************************/
void MCP2515_Reset()
{
    uint8_t tx = RESET;
    SPI_Transfer(&tx, NULL, 1);
    usleep(10000); // Attendre 10ms pour le reset
}
/***********************************************************************************************************************************/

/********************************************************* MCP READ ****************************************************************/
void MCP2515_Read(uint8_t address, uint8_t *data, size_t length)
{
    uint8_t tx[length + 2];
    uint8_t rx[length + 2];
    tx[0] = READ;
    tx[1] = address;
    memset(&tx[2], 0x00, length);     // Remplir le reste avec des zéros
    SPI_Transfer(tx, rx, length + 2); // Transfert SPI
    memcpy(data, &rx[2], length);     // Copier les données reçues
}
/***********************************************************************************************************************************/

/******************************************************** MCP Write ****************************************************************/
void MCP2515_Write(uint8_t address, uint8_t *data, size_t length)
{
    uint8_t tx[length + 2];
    tx[0] = WRITE;
    tx[1] = address;
    memcpy(&tx[2], data, length);       // Copier les données à écrire
    SPI_Transfer(tx, NULL, length + 2); // Transfert SPI
}
/***********************************************************************************************************************************/

/****************************************************** MCP Bit Modify *************************************************************/
void MCP2515_BitModify(uint8_t address, uint8_t mask, uint8_t data)
{
    uint8_t tx[4];
    tx[0] = BIT_MODIFY;
    tx[1] = address;
    tx[2] = mask;
    tx[3] = data;
    SPI_Transfer(tx, NULL, 4);
}
/***********************************************************************************************************************************/

/********************************************************** MCP RTS ****************************************************************/
void MCP2515_RTS(uint8_t tx_buffer)
{
    uint8_t rts_command;
    switch (tx_buffer)
    {
    case 0:
        rts_command = RTS_TXB0; // 0x80
        break;
    case 1:
        rts_command = RTS_TXB1; // 0x82
        break;
    case 2:
        rts_command = RTS_TXB2; // 0x84
        break;
    default:
        return; // Invalid buffer number
    }
    SPI_Transfer(&rts_command, NULL, 1);
}
/***********************************************************************************************************************************/

/******************************************************* MCP RX Status *************************************************************/
uint8_t MCP2515_RXSTATUS()
{
    uint8_t tx[2] = {RX_STATUS, 0x00};
    uint8_t rx[2] = {0x00, 0x00};
    SPI_Transfer(tx, rx, 2);
    return rx[1];
}
/***********************************************************************************************************************************/

/****************************************************** MCP READ Status ************************************************************/
uint8_t MCP2515_ReadStatus()
{
    uint8_t tx[2] = {READ_STATUS, 0x00};
    uint8_t rx[2] = {0x00, 0x00};
    SPI_Transfer(tx, rx, 2);
    return rx[1];
}
/***********************************************************************************************************************************/

/**************************************************** MCP READ RX BUFFER ***********************************************************/
void MCP2515_ReadRxBuffer(uint8_t buffer, uint8_t *data, size_t length, uint8_t extended)
{
    if (length > 8)
        length = 8;

    uint8_t command;

    if (buffer == 0)
        command = READ_RXB0_STD; // 0x90
    else if (buffer == 1)
        command = READ_RXB1_STD; // 0x98
    else
        return;

    // Il faut lire 5 octets de plus pour SIDH, SIDL, EID8, EID0, DLC
    uint8_t tx[length + 6]; // +1 commande, +5 octets d'entête
    uint8_t rx[length + 6];

    tx[0] = command;
    memset(&tx[1], 0x00, length + 5);

    SPI_Transfer(tx, rx, length + 6);

    // Les données commencent à rx[6] (après cmd + 5 octets d'entête)
    memcpy(data, &rx[6], length);
}
/***********************************************************************************************************************************/

/************************************************** MCP Load TX Buffer *************************************************************/
void MCP2515_LoadTxBuffer(uint8_t tx_buffer, uint8_t *data, size_t length, uint8_t extended)
{
    if (length > 8)
        length = 8; // max 8 octets de données
    uint8_t command = 0;

    // Choix du buffer et de la zone DATA0..DATA7
    switch (tx_buffer)
    {
    case 0:
        command = LOAD_TXB0_D0;
        break; // TXB0 DATA0..7
    case 1:
        command = LOAD_TXB1_D0;
        break; // TXB1 DATA0..7
    case 2:
        command = LOAD_TXB2_D0;
        break; // TXB2 DATA0..7
    default:
        return; // invalid buffer
    }

    // Créer tableau SPI : commande + données
    uint8_t tx[length + 1];
    tx[0] = command;
    memcpy(&tx[1], data, length);

    // Envoyer via SPI
    SPI_Transfer(tx, NULL, length + 1);
}
/***********************************************************************************************************************************/

/***************************************************** MCP Set Mode ****************************************************************/
void MCP2515_SetMode(uint8_t mode)
{
    MCP2515_BitModify(MCP_CANCTRL, 0xE0, mode);
    uint8_t canstat = 0;
    do
    {
        MCP2515_Read(MCP_CANSTAT, &canstat, 1);
        canstat &= 0xE0; // garder uniquement les bits de mode
    } while (canstat != mode);
}
/***********************************************************************************************************************************/

/**************************************************** MCP Set Bitrate **************************************************************/
int MCP2515_SetBitrate(uint16_t bitrate_kbps)
{
    uint8_t cnf1, cnf2, cnf3;

    switch (bitrate_kbps)
    {
    case 125: // 125 kbps
        // On simule un quartz de 16 MHz
        cnf1 = 0x01; // BRP=3 → TQ = 4/16MHz = 0.25µs
        cnf2 = 0xb1; // BTLMODE=1, SAM=0, PHSEG1=4TQ, PRSEG=1TQ
        cnf3 = 0x85; // PHSEG2=5TQ, WAKFIL=0
        break;

    case 250: // 250 kbps
        cnf1 = 0x01;
        cnf2 = 0xB1;
        cnf3 = 0x05;
        break;

    case 500: // 500 kbps
        cnf1 = 0x00;
        cnf2 = 0x90;
        cnf3 = 0x02;
        break;

    case 50: // 50 kbps
        cnf1 = 0x07;
        cnf2 = 0xB1;
        cnf3 = 0x05;
        break;

    default:
        return -1; // Bitrate non supporté
    }

    MCP2515_Write(CNF1, &cnf1, 1);
    MCP2515_Write(CNF2, &cnf2, 1);
    MCP2515_Write(CNF3, &cnf3, 1);

    return 0;
}
/***********************************************************************************************************************************/

/************************************************** MCP Configure RX Filters *******************************************************/
void MCP2515_ConfigRxFilters(uint8_t disable_filters)
{
    uint8_t mask = 0x00; /* Masques RX */
    uint8_t rxb = 0x64;  /* Contrôle RXB0 et RXB1 : filtre standard */

    if (disable_filters)
    {
        /* Masques RX à 0 pour accepter toutes les trames */
        MCP2515_Write(MCP_RXM0SIDH, &mask, 1);
        MCP2515_Write(MCP_RXM0SIDL, &mask, 1);
        MCP2515_Write(MCP_RXM1SIDH, &mask, 1);
        MCP2515_Write(MCP_RXM1SIDL, &mask, 1);

        /* Désactiver les filtres stricts sur RXB0/RXB1 */
        MCP2515_Write(MCP_RXB0CTRL, &rxb, 1);
        MCP2515_Write(MCP_RXB1CTRL, &rxb, 1);
    }
}
/***********************************************************************************************************************************/

/********************************************************* MCP Init ****************************************************************/
int MCP2515_Init()
{
    // --- Initialisation SPI ---
    if (SPI_Init() < 0)
    {
        printf("Erreur SPI\n");
        return -1;
    }
    printf("SPI Initialise ✅\n");

    // --- Reset MCP2515 ---
    MCP2515_Reset();
    printf("MCP2515 reset ✅\n");

    // --- Passage en mode CONFIG ---
    MCP2515_SetMode(MODE_CONFIG);
    printf("MCP2515 en mode Config ✅\n");

    // --- Configuration bitrate ---
    if (MCP2515_SetBitrate(BIT_RATE) < 0)
    {
        printf(" Bitrate non applicable\n");
        printf("Choix entre 800, 500, 250, 125, 50\n");
        return -1;
    }
    printf("Bitrate est set a %d kBit/sec ✅\n", BIT_RATE);

    // --- Désactivation filtres RX ---
    MCP2515_ConfigRxFilters(1);
    printf("Filtres RX désactivés ✅\n");

    // --- Passage en mode NORMAL ---
    MCP2515_SetMode(MODE_NORMAL);
    printf("MCP2515 en mode Normal ✅\n");

    return 0;
}
/***********************************************************************************************************************************/