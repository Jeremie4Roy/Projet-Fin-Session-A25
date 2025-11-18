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

// device port série à utiliser 
//const char *portTTY = "/dev/ttyGS0"; 
//const char *portTTY = "/dev/ttyS0";
//const char *portTTY = "/dev/ttyS1";
//const char *portTTY = "/dev/ttyS2";
//const char *portTTY = "/dev/ttyS3";
//const char *portTTY = "/dev/ttyS4";
//const char *portTTY = "/dev/ttyS5";
const char *portTTY = "/dev/ttyAMA0"; // ttyUSB0 is the FT232 based USB2SERIAL Converter

void main()
{
    
}