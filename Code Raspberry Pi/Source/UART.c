#define _GNU_SOURCE
#include <stdio.h>
#include <fcntl.h>   // File Control Definitions
#include <termios.h> // POSIX Terminal Control Definitions
#include <unistd.h>  // UNIX Standard Definitions
#include <errno.h>   // ERROR Number Definitions
#include <string.h>
#include "../Include/UART.h"

void UartInit(speed_t BaudRate)
{
    fd = open("/dev/ttyAMA0", O_RDWR | O_NOCTTY);
    if (fd != -1)
    {

        tcgetattr(fd, &SerialPortSettings);

        cfsetispeed(&SerialPortSettings, BaudRate);

        SerialPortSettings.c_cflag &= ~PARENB;        // Disables the Parity Enable bit(PARENB),So No Parity
        SerialPortSettings.c_cflag &= ~CSTOPB;        // CSTOPB = 2 Stop bits,here it is cleared so 1 Stop bit
        SerialPortSettings.c_cflag &= ~CSIZE;         // Clears the mask for setting the data size
        SerialPortSettings.c_cflag |= CS8;            // Set the data bits = 8
        SerialPortSettings.c_cflag &= ~CRTSCTS;       // No Hardware flow Control
        SerialPortSettings.c_cflag |= CREAD | CLOCAL; // Enable receiver, Ignore Modem Control lines

        SerialPortSettings.c_iflag &= ~(IXON | IXOFF | IXANY); // Disable XON/XOFF flow control both i/p and o/p

        SerialPortSettings.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG); // Non Cannonical mode, Disable echo, Disable signal
                                                                       // SerialPortSettings.c_lflag &= ~(ECHO | ECHOE | ISIG);  // Cannonical mode, Disable echo, Disable signal
        SerialPortSettings.c_oflag &= ~OPOST;                          // No Output Processing

        SerialPortSettings.c_cc[VMIN] = 0;   // Read at least X character(s)
        SerialPortSettings.c_cc[VTIME] = 10; // Wait 1sec (0 for indefinetly)
    }
}

void CloseUart()
{
    close(fd);
}

void UartWrite()
{
}

int UartRead(char *buffer[32], int length)
{
    tcflush(fd, TCIFLUSH);
    return read(fd, buffer, length);
}