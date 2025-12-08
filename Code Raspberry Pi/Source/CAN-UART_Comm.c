/**
 * @file UART-CAN_Comm.c
 * @brief Serial port programming in C. Reads the CAN/SPI, writes in the UART..
 * @author Jeremie Roy
 * @date 2025-11-18
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
#include <pthread.h>

// device port série à utiliser
// const char *portTTY = "/dev/ttyGS0";
// const char *portTTY = "/dev/ttyS0";
// const char *portTTY = "/dev/ttyS1";
// const char *portTTY = "/dev/ttyS2";
// const char *portTTY = "/dev/ttyS3";
// const char *portTTY = "/dev/ttyS4";
// const char *portTTY = "/dev/ttyS5";
const char *portTTY = "/dev/ttyAMA0"; // ttyUSB0 is the FT232 based USB2SERIAL Converter

void main()
{
    pthread_t thread_can_rx;
    if (pthread_create(&thread_can_rx, NULL, CAN_Thread_RX, NULL) != 0)
    {
        perror("Erreur création de thread CAN RX");
        return;
    }
    printf("PThread démarré");
    UartInit(B19200);
    if ((tcsetattr(fd, TCSANOW, &SerialPortSettings)) != 0)
    {
        printf("\nErreur! Configuration des attributs du port série");
    }
    else
    {
        while (1)
        {
            if (CAN_Read_Flag)
            {
                CAN_Read_Flag = 0;
            }
        }
    }
    pthread_join(thread_can_rx, NULL);
}