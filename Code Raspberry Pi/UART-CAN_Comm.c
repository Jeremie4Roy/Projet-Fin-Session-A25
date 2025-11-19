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
#include <sys/socket.h>
#include <arpa/inet.h>

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
    int fd;
    //Ouverture de ports
    fd = open(portTTY, O_RDWR | O_NOCTTY);
    if(fd == -1)
    {
        printf("\nErreur! ouverture de %s", portTTY);
        close(fd);
    }else
    {
        printf("\n Ouverture de %s réussite\n", portTTY);
        struct termios SerialPortSettings;

        tcgetattr(fd, &SerialPortSettings);

        cfsetispeed(&SerialPortSettings, B19200);

        SerialPortSettings.c_cflag &= ~PARENB;   // Disables the Parity Enable bit(PARENB),So No Parity 
	    SerialPortSettings.c_cflag &= ~CSTOPB;   // CSTOPB = 2 Stop bits,here it is cleared so 1 Stop bit
	    SerialPortSettings.c_cflag &= ~CSIZE;	 // Clears the mask for setting the data size 
	    SerialPortSettings.c_cflag |=  CS8;      // Set the data bits = 8  
	    SerialPortSettings.c_cflag &= ~CRTSCTS;       // No Hardware flow Control
	    SerialPortSettings.c_cflag |= CREAD | CLOCAL; // Enable receiver, Ignore Modem Control lines
	
	    SerialPortSettings.c_iflag &= ~(IXON | IXOFF | IXANY);          // Disable XON/XOFF flow control both i/p and o/p

	    SerialPortSettings.c_lflag &= ~( ICANON | ECHO | ECHOE | ISIG);  // Non Cannonical mode, Disable echo, Disable signal  
        //SerialPortSettings.c_lflag &= ~(ECHO | ECHOE | ISIG);  // Cannonical mode, Disable echo, Disable signal  
	    SerialPortSettings.c_oflag &= ~OPOST;	// No Output Processing

        SerialPortSettings.c_cc[VMIN] = 0; // Read at least X character(s) 
	    SerialPortSettings.c_cc[VTIME] = 10; // Wait 1sec (0 for indefinetly) 

        if((tcsetattr(fd, TCSANOW, &SerialPortSettings))!= 0)
        {
            printf("\nErreur! Configuration des attributs du port série");
        }else{
            printf("Début de lecture: \n");
            char read_buffer[32] = "";
            int read_byte = 0;
            int i = 0;

            while(!(read_buffer == "12345ABCDE\n"))
            {
                tcflush(fd,TCIFLUSH);
                read_byte = 0;
                for (i = 0; i > 32; i++)
                {
                    read_buffer[i] = 0;
                }

                read_byte = read(fd,&read_buffer, 32);
                if(read_byte > 0)
                {
                    printf("Données reçu: ");
                   for(i = 0; i < read_byte; i++)
                    {
                        printf("%c",read_buffer[i]);
                    }
                }
            }
        }
    }
}
