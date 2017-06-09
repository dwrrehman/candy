// server - pi3.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

int portno = 6001;

int main(int argc, char *argv[])
{
     int newsockfd2, newsockfd0, newsockfd2_camera;

     socklen_t clilen;
     struct sockaddr_in serv_addr, cli_addr;

     char buffer[256];
     char camera_buffer[256];
     
     int sockfd = socket(AF_INET, SOCK_STREAM, 0);
     bzero((char *) &serv_addr, sizeof(serv_addr));
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
     listen(sockfd,5);
     clilen = sizeof(cli_addr);
     newsockfd2 = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
     newsockfd2_camera = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
     newsockfd0 = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
     if (newsockfd2 < 0 || newsockfd0 < 0) printf("a pi3 accept: a connection failure.");

     while (1) {

        bzero(buffer,256);
        read(newsockfd2, buffer, 255);
        printf("pi2 message: %s\n", buffer);

        bzero(buffer,256);
        read(newsockfd0, buffer, 255);
        printf("pi0 message: %s\n", buffer);

        bzero(camera_buffer,256);
        read(newsockfd2_camera, camera_buffer, 255);
        printf("pi2 camera message: %s\n", camera_buffer);


        bzero(buffer, 256);
        printf("m> ");
        fgets(buffer, 255, stdin);
        write(newsockfd2, buffer, strlen(buffer));
        write(newsockfd0, buffer, strlen(buffer));

        bzero(camera_buffer, 256);
        printf("c> ");
        fgets(camera_buffer, 255, stdin);
        write(newsockfd2_camera, camera_buffer, strlen(camera_buffer));
        

    }
    close(newsockfd2);
    close(newsockfd0);
    close(newsockfd2_camera);
    close(sockfd);
     return 0; 
}