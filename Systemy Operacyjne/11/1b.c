#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
int main(){
    int pdesk;
    mkfifo("/tmp/fifo", 0600);
    if( fork() == 0){ // proces potomny
        pdesk = open("/tmp/fifo", O_WRONLY);
        write(pdesk, "Hallo!", 7);
        exit(0);
    }else { //proces macierzysty
        char buf[10];
        pdesk = open("/tmp/fifo",O_RDONLY);
        read(pdesk, buf, 7);
        printf("Odczytano z fifo: %s\n", buf);
    }
    exit(0);
}
