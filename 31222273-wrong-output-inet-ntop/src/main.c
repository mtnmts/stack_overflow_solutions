#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]){
    int sock = socket(AF_INET, SOCK_STREAM, 0); 
    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = 0;
    hints.ai_flags = 0;

    int s = getaddrinfo("irc.root-me.org", "6667", &hints, &result);
    if( s != 0){ 
        printf("erreur\n");
        exit(EXIT_FAILURE);
    }   

    int f = connect(sock, result->ai_addr, result->ai_addrlen);
    if(f != 0){ 
        printf("erreur connect\n");
    }   

    struct sockaddr_in *sockin;  
    sockin = (struct sockaddr_in *)result->ai_addr;
    char dst[100] = {0};
    inet_ntop(AF_INET, &sockin->sin_addr, dst, sizeof(dst));
    printf("%s\n", dst);
    freeaddrinfo(result);

    exit(0);
}
