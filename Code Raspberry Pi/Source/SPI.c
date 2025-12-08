/*
 * SPI.h
 * @author  Anthony Ducharme
 * @date    2025-12-01
 * Fichier d'initialisation SPI
 */

#include "../Include/SPI.h"
#include <stdio.h>     // perror, printf
#include <fcntl.h>     // open()
#include <unistd.h>    // close()
#include <sys/ioctl.h> // ioctl()

/***************************************************** Variable SPI globale ****************************************************/
int spi_file = -1;
/*******************************************************************************************************************************/

/****************************************************** Initialisation SPI *****************************************************/
int SPI_Init(void)
{
    spi_file = open(SPI_DEVICE, O_RDWR);
    if (spi_file < 0)
    {
        perror("SPI_Init: Unable to open SPI device ");
        return -1;
    }
    uint8_t mode = SPI_MODE_SET;
    uint8_t bits = SPI_BITS_PER_WORD;
    uint32_t speed = SPI_SPEED_HZ;
    if (ioctl(spi_file, SPI_IOC_WR_MODE, &mode) == -1 || ioctl(spi_file, SPI_IOC_WR_BITS_PER_WORD, &bits) == -1 || ioctl(spi_file, SPI_IOC_WR_MAX_SPEED_HZ, &speed) == -1)
    {
        perror("SPI_Init: Failed to set SPI parameters ");
        close(spi_file);
        return -1;
    }
    return spi_file;
}
/*******************************************************************************************************************************/

/******************************************************* Transfer SPI **********************************************************/
int SPI_Transfer(uint8_t *tx_buffer, uint8_t *rx_buffer, size_t length)
{
    if (length == 0)
        return -1;
    if (tx_buffer == NULL)
        return -1;

    uint8_t temp_rx[length];
    if (rx_buffer == NULL)
        rx_buffer = temp_rx;

    struct spi_ioc_transfer transfer = {
        .tx_buf = (unsigned long)tx_buffer,
        .rx_buf = (unsigned long)rx_buffer,
        .len = length,
        .speed_hz = SPI_SPEED_HZ,
        .bits_per_word = SPI_BITS_PER_WORD,
        .delay_usecs = 0,
    };
    int ret = ioctl(spi_file, SPI_IOC_MESSAGE(1), &transfer);
    if (ret < 1)
    {
        perror("SPI_Transfer: SPI transfer failed");
        return -1;
    }
    return 0;
}
/*******************************************************************************************************************************/

/******************************************************** SPI Close ************************************************************/
void SPI_Close(void)
{
    if (spi_file >= 0)
    {
        close(spi_file);
        spi_file = -1;
    }
}
/*******************************************************************************************************************************/