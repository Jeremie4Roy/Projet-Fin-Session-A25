/*
 * SPI.h
 * @author  Anthony Ducharme
 * @date    2025-12-01
 * Fichier d'initialisation SPI
 */

#ifndef SPI_H
#define SPI_H

#include <stdint.h>               // uint8_t, uint32_t
#include <stddef.h>               // size_t si jamais tu l’utilises
#include <linux/spi/spidev.h>     // définitions SPI (SPI_IOC_*, spi_ioc_transfer)

/****************************************************** DEFINE SPI *************************************************************/
#define SPI_DEVICE        "/dev/spidev0.0"
#define SPI_MODE_SET      SPI_MODE_0
#define SPI_BITS_PER_WORD 8
#define SPI_SPEED_HZ      6000000  // 6 MHz
/*******************************************************************************************************************************/


/***************************************************** Variable SPI globale ****************************************************/
extern int spi_file;
/*******************************************************************************************************************************/


/********************************************************** Prototypes *********************************************************/
int SPI_Init (void);
int SPI_Transfer(uint8_t *tx_buffer, uint8_t *rx_buffer, size_t length);
void SPI_Close(void);
/*******************************************************************************************************************************/

#endif