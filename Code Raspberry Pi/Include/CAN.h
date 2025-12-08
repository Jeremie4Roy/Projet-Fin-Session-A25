/*
 * ÇAN_BUS.h
 * @author  Anthony Ducharme
 * @date    2025-12-01
 * Driver pour CAN a partir du MCP2515
 */

#ifndef CAN_BUS_H
#define CAN_BUS_H

#include <stdint.h>
#include <stdbool.h>
bool CAN_Read_Flag = 0;
uint16_t CAN_id;
uint8_t CAN_Buffer[8];
uint8_t CAN_Length;
/********************************************************** Prototypes *********************************************************/
void SendCANFrame(uint16_t id, uint8_t *data, uint8_t length);
void SendCanFrame_Float(uint16_t id, float value);
int ReadCANFrame(uint16_t *id, uint8_t *data, uint8_t *length);
void *CAN_Thread_RX(void *arg);
/*******************************************************************************************************************************/

#endif