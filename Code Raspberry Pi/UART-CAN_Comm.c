/**
*@file UART-CAN_Comm.c
*@brief Programme pont entre la communication UART et la communication CAN en passant par le SPI
*@author Jeremie Roy
*@date 2025-11-14
*/
#define _GNU_SURCE

#include <stdio.h>
#include <fcntl.h>   // File Control Definitions
#include <termios.h> // POSIX Terminal Control Definitions
#include <unistd.h>  // UNIX Standard Definitions
#include <errno.h>   // ERROR Number Definitions
#include <string.h>
#include <arpa/inet.h> // allows to send data to the net via the ehternet port
#include <linux/spi/spidev.h>
#include <sys/socket.h>

const char *remote_address = "172.18.42.34";


void main()
{
    int sock = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(5000);                    // destination port
    inet_pton(AF_INET, "172.18.42.34", &addr.sin_addr); // destination IP

    char message[] = "Hello over Ethernet!";
    sendto(sock, message, strlen(message), 0,
           (struct sockaddr*)&addr, sizeof(addr));

    close(sock);
    //Ouverture des ports

    //fork()

    //Processus fils(écoute le UART et envoie sur le SPI/CAN)

    //Processus père (écoute le SPI/CAN et envoie sur le UART)

    //fermeture des ports
}