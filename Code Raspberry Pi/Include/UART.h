#ifndef UART_H
#define UART_H

#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

extern int fd;
extern struct termios SerialPortSettings;

int UartInit(speed_t BaudRate);
void CloseUart();
int UartRead(char *buffer, int length);

#endif
