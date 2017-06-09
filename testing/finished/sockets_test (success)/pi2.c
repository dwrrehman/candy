#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

int portno = 6001;


int main(int argc, char *argv[])
{
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
    char camera_buffer[256];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    int sockfd_camera = socket(AF_INET, SOCK_STREAM, 0);
    server = gethostbyname("127.0.0.1");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0 || connect(sockfd_camera,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        printf("pi2 to pi3: a connection failure.");

    while (1) {

        bzero(buffer,256);  
        printf("m> ");
        fgets(buffer,255,stdin);
        write(sockfd,buffer,strlen(buffer));
        // -------
        bzero(camera_buffer,256);  
        printf("c> ");
        fgets(camera_buffer,255,stdin);
        write(sockfd_camera,camera_buffer,strlen(camera_buffer));


        bzero(buffer,256);
        read(sockfd,buffer,255);
        printf("pi3 motor message: %s\n", buffer);
        // --------
        bzero(camera_buffer,256);
        read(sockfd_camera,camera_buffer,255);
        printf("pi3 camera message: %s\n", camera_buffer);
    }

    close(sockfd);
    close(sockfd_camera);
    return 0;
}