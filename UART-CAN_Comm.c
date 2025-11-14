/**
*@file UART-CAN_Comm.c
*@brief Programme pont entre la communication UART et la communication CAN en passant par le SPI
*@author Jeremie Roy
*@date 2025-11-14
*/

#include <stdio.h>
#include <fcntl.h>   // File Control Definitions
#include <termios.h> // POSIX Terminal Control Definitions
#include <unistd.h>  // UNIX Standard Definitions
#include <errno.h>   // ERROR Number Definitions
#include <string.h>
#include <arpa/inet.h> // allows to send data to the net via the ehternet port
#include <linux/spi/spidev.h>


void main()
{
    
}