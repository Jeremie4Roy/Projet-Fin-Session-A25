#define _GNU_SOURCE
#include "../Include/UART.h"

int fd;  // définition réelle
struct termios SerialPortSettings;

int UartInit(speed_t BaudRate)
{
    fd = open("/dev/ttyAMA0", O_RDWR | O_NOCTTY);

    if (fd < 0)
    {
        perror("Erreur open UART");
        return -1;
    }

    if(tcgetattr(fd, &SerialPortSettings) != 0)
    {
        return -1;
    }

    if(cfsetispeed(&SerialPortSettings, BaudRate) != 0)
    {
        return -1;
    }
    if(cfsetospeed(&SerialPortSettings, BaudRate) != 0)
    {
        return -1;
    }


    SerialPortSettings.c_cflag &= ~PARENB;
    SerialPortSettings.c_cflag &= ~CSTOPB;
    SerialPortSettings.c_cflag &= ~CSIZE;
    SerialPortSettings.c_cflag |= CS8;
    SerialPortSettings.c_cflag &= ~CRTSCTS;
    SerialPortSettings.c_cflag |= CREAD | CLOCAL;

    SerialPortSettings.c_iflag &= ~(IXON | IXOFF | IXANY);
    SerialPortSettings.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    SerialPortSettings.c_oflag &= ~OPOST;

    SerialPortSettings.c_cc[VMIN] = 0;
    SerialPortSettings.c_cc[VTIME] = 10;

    if(tcsetattr(fd, TCSANOW, &SerialPortSettings) != 0)
    {
        return -1;
    }
    return 0;
}

int UartRead(char *buffer, int length)
{
    return read(fd, buffer, length);
}

void CloseUart()
{
    close(fd);
}
