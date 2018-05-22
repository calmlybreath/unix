#include <stdio.h>
#include <zconf.h>
#include <signal.h>
#include "./include/net.h"


#define offest(type, member) (void *)&(((struct type *)0)->member)

struct test {
    int a;
    double b;
    int c;
};

void handler(int sig) {
    pid_t pid;
    pid = fork();
    if (pid > 0) {
        //children
        for(int i = 1; i < 5; i++)
        {
            printf("children sleep %d ...\n", i);
            sleep(1);
        }
        _exit(1);
    } else if (pid == 0) {
        //father
        printf("create children successful\n");
    }
}

int main() {
}