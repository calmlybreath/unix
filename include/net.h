//
// Created by lrq on 18-5-18.
//

#ifndef UTIL_NET_H
#define UTIL_NET_H

#include <sys/socket.h>
#include <stdint.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int net_listen_tcp(uint16_t host);
int net_listen_udp(uint16_t host);
int net_listen(uint16_t server_host, const char * protocol);

#endif //UTIL_NET_H
