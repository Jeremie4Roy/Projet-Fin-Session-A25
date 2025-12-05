/*
 * mcp2515.h
 * @author  Anthony Ducharme
 * @date    2025-12-01
 * Driver pour contrôleur CAN MCP2515 via SPI
 */

#ifndef MCP2515_H
#define MCP2515_H

#include <stdint.h>
#include <stddef.h>
#include "SPI.h"

/****************************************************** MCP2515 COMMANDES ***************************************************/
#define BIT_RATE          125  // kbps
#define RESET             0xC0
#define READ              0x03
#define READ_RXB0_STD     0x90
#define READ_RXB0_EXT     0x94
#define READ_RXB1_STD     0x98
#define READ_RXB1_EXT     0x9C
#define WRITE             0x02
#define LOAD_TXB0_SIDH    0x40
#define LOAD_TXB0_D0      0x41
#define LOAD_TXB1_SIDH    0x42
#define LOAD_TXB1_D0      0x43
#define LOAD_TXB2_SIDH    0x44
#define LOAD_TXB2_D0      0x45
#define RTS_TXB0          0x81
#define RTS_TXB1          0x82
#define RTS_TXB2          0x84
#define READ_STATUS       0xA0
#define RX_STATUS         0xB0
#define BIT_MODIFY        0x05
/****************************************************************************************************************************/

/****************************************************** MCP2515 REGISTRES ***************************************************/
#define MCP_TXB0CTRL      0x30
#define MCP_TXB0SIDH      0x31
#define MCP_TXB0SIDL      0x32
#define MCP_TXB0EID8      0x33
#define MCP_TXB0EID0      0x34
#define MCP_TXB0DLC       0x35
#define MCP_TXB0DATA      0x36

#define MCP_TXB1CTRL      0x40
#define MCP_TXB1SIDH      0x41
#define MCP_TXB1SIDL      0x42
#define MCP_TXB1EID8      0x43
#define MCP_TXB1EID0      0x44
#define MCP_TXB1DLC       0x45
#define MCP_TXB1DATA      0x46

#define MCP_TXB2CTRL      0x50
#define MCP_TXB2SIDH      0x51
#define MCP_TXB2SIDL      0x52
#define MCP_TXB2EID8      0x53
#define MCP_TXB2EID0      0x54
#define MCP_TXB2DLC       0x55
#define MCP_TXB2DATA      0x56

#define MCP_RXB0CTRL      0x60
#define MCP_RXB0SIDH      0x61
#define MCP_RXB0SIDL      0x62
#define MCP_RXB0EID8      0x63
#define MCP_RXB0EID0      0x64
#define MCP_RXB0DLC       0x65
#define MCP_RXB0D0        0x66
#define MCP_RXB0D1        0x67
#define MCP_RXB0D2        0x68
#define MCP_RXB0D3        0x69
#define MCP_RXB0D4        0x6A
#define MCP_RXB0D5        0x6B
#define MCP_RXB0D6        0x6C
#define MCP_RXB0D7        0x6D

#define MCP_RXB1CTRL      0x70
#define MCP_RXB1SIDH      0x71
#define MCP_RXB1SIDL      0x72
#define MCP_RXB1EID8      0x73
#define MCP_RXB1EID0      0x74
#define MCP_RXB1DLC       0x75
#define MCP_RXB1D0        0x76
#define MCP_RXB1D1        0x77
#define MCP_RXB1D2        0x78
#define MCP_RXB1D3        0x79
#define MCP_RXB1D4        0x7A
#define MCP_RXB1D5        0x7B
#define MCP_RXB1D6        0x7C
#define MCP_RXB1D7        0x7D

#define MCP_CANCTRL       0x0F
#define MCP_CANSTAT       0x0E
#define MCP_EFLG          0x2D
#define MCP_TEC           0x1C
#define MCP_REC           0x1D
#define CNF1              0x2A
#define CNF2              0x29
#define CNF3              0x28
#define MCP_CANINTE       0x2B
#define MCP_CANINTF       0x2C
#define MCP_RXM0SIDH      0x20
#define MCP_RXM0SIDL      0x21
#define MCP_RXM1SIDH      0x24
#define MCP_RXM1SIDL      0x25
#define MCP_RXF0SIDH      0x00
#define MCP_RXF0SIDL      0x01
#define MCP_RXF1SIDH      0x04
#define MCP_RXF1SIDL      0x05
#define MCP_RXF2SIDH      0x08
#define MCP_RXF2SIDL      0x09
#define MCP_RXF3SIDH      0x10
#define MCP_RXF3SIDL      0x11
#define MCP_RXF4SIDH      0x14
#define MCP_RXF4SIDL      0x15
#define MCP_RXF5SIDH      0x18
#define MCP_RXF5SIDL      0x19
/****************************************************************************************************************************/

/****************************************************** MCP2515 MODES *******************************************************/
#define MODE_NORMAL       0x00
#define MODE_SLEEP        0x20
#define MODE_LOOPBACK     0x40
#define MODE_LISTENONLY   0x60
#define MODE_CONFIG       0x80
#define MCP_RTS           0x80
/****************************************************************************************************************************/


/********************************************************** Prototypes *********************************************************/
void MCP2515_Reset(void);
void MCP2515_Write(uint8_t address, uint8_t *data, size_t length);
void MCP2515_Read(uint8_t address, uint8_t *data, size_t length);
void MCP2515_BitModify(uint8_t address, uint8_t mask, uint8_t data);
void MCP2515_RTS(uint8_t tx_buffer);
uint8_t MCP2515_RXSTATUS(void);
uint8_t MCP2515_ReadStatus(void);
void MCP2515_ReadRxBuffer(uint8_t buffer, uint8_t *data, size_t length, uint8_t extended);
void MCP2515_LoadTxBuffer(uint8_t tx_buffer, uint8_t *data, size_t length, uint8_t extended);
void MCP2515_SetMode(uint8_t mode);
int MCP2515_SetBitrate(uint16_t bitrate_kbps);
void MCP2515_ConfigRxFilters(uint8_t disable_filters);
int MCP2515_Init(void);
/*******************************************************************************************************************************/





#endif