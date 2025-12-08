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

// device port série à utiliser
// const char *portTTY = "/dev/ttyGS0";
// const char *portTTY = "/dev/ttyS0";
// const char *portTTY = "/dev/ttyS1";
// const char *portTTY = "/dev/ttyS2";
// const char *portTTY = "/dev/ttyS3";
// const char *portTTY = "/dev/ttyS4";
// const char *portTTY = "/dev/ttyS5";
const char *portTTY = "/dev/ttyAMA0"; // ttyAMA0 is the for uart with the pins

void main()
{
    UartInit(B19200);

    if ((tcsetattr(fd, TCSANOW, &SerialPortSettings)) != 0)
    {
        printf("\nErreur! Configuration des attributs du port série");
    }
    else
    {
        printf("Début de lecture: \n");
        char read_buffer[32] = "";
        int read_byte = 0;
        int i = 0;
        while (1)
        {
            tcflush(fd, TCIFLUSH);
            read_byte = 0;
            for (i = 0; i < 32; i++)
            {
                read_buffer[i] = 0;
            }
            read_byte = read(fd, &read_buffer, 32);
            if (read_byte > 0)
            {
                printf("Données reçu: ");
                for (i = 0; i < read_byte; i++)
                {
                    printf("%c", read_buffer[i]);
                }
            }
            if (strcmp(read_buffer, "12345ABCDE\n") == 0)
            {
                close(fd);
                return;
            }
        }
    }
}