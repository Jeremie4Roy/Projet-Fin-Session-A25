#include <stdio.h>
#include <fcntl.h>   // File Control Definitions
#include <termios.h> // POSIX Terminal Control Definitions
#include <unistd.h>  // UNIX Standard Definitions
#include <errno.h>   // ERROR Number Definitions

#ifndef UART
#define UART

 void UartInit(speed_t BaudRate);
 void CloseUart();
 int fd;
 struct termios SerialPortSettings;
#endif

