//
// Created by lrq on 18-5-22.
//
#include "../include/net.h"

int net_listen(uint16_t server_host, const char * protocol){
    int server_fd;
    if(strcmp(protocol,"tcp")==0){
        server_fd = socket(AF_INET, SOCK_STREAM, 0); //AF_INET:IPV4;SOCK_DGRAM:UDP
    } else{
        server_fd = socket(AF_INET, SOCK_DGRAM, 0); //AF_INET:IPV4;SOCK_DGRAM:UDP
    }

    if (server_fd < 0) {
        perror("create socket error");
        exit(-1);
    }

    struct sockaddr_in server_sockaddr;
    memset(&server_sockaddr, 0, sizeof(server_sockaddr));

    server_sockaddr.sin_family = AF_INET;
    server_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY); //IP地址，需要进行网络序转换，INADDR_ANY：本地地址
    server_sockaddr.sin_port = htons(server_host);  //端口号，需要网络序转换

    if(bind(server_fd, (struct sockaddr *) &server_sockaddr, sizeof(server_sockaddr))==-1){
        perror("bind error");
        exit(-1);
    }

    return server_fd;
}

int net_listen_tcp(uint16_t server_host) {
    return net_listen(server_host,"tcp");
}

int net_listen_udp(uint16_t server_host) {
    return net_listen(server_host,"udp");
}



