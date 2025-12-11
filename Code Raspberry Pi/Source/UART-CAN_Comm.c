/**
 * @file UART-CAN_Comm.c
 * @brief Serial port programming in C. Reads the UART, writes in the CAN/SPI.
 * @author Jeremie Roy
 * @date 2025-11-17
 */

#define _GNU_SOURCE

#include <stdio.h>
#include <fcntl.h>   // File Control Definitions
#include <termios.h> // POSIX Terminal Control Definitions
#include <unistd.h>  // UNIX Standard Definitions
#include <errno.h>   // ERROR Number Definitions
#include <string.h>
#include <string.h>
#include "UART.c"
#include "CAN.c"

void main()
{
    if (UartInit(B19200) != 0)
    {
        printf("Erreur: initionalisation uart");
    }
    else
    {
        if (MCP2515_Init() < 0)
        {
            printf("Erreur de communicaiton entre le SPI et le MCP2515");
        }
        else
        {
            printf("Début de lecture: \n");
            char read_buffer[32] = "";
            int read_byte = 0;
            int i = 0;
            while (1)
            {
                read_byte = 0;
                for (i = 0; i < 32; i++)
                {
                    read_buffer[i] = 0;
                }
                read_byte = UartRead(read_buffer, 32);
                if (read_byte > 0)
                {
                    // SendCANFrame(0x101, 0xFF, 1);
                    printf("Données reçu: ");
                    for (i = 0; i < read_byte; i++)
                    {
                        printf("%c", read_buffer[i]);
                    }
                }
                /*if (strcmp(read_buffer, "12345ABCDE\n") == 0)
                {
                    close(fd);
                    return;
                }*/
            }
        }
    }
    CloseUart();
}