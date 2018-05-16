#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int pdesk[2];
    pipe(pdesk);
    if( fork() == 0 ) { //Proces macierzysty
        write(pdesk[1], "Hallo!", 7);
        exit(0);
    }else { //proces macierzysty
        char buf[10];
        read(pdesk[0],buf,7);
        printf("Odczytano z potoku: %s\n", buf);
    }
    exit(0);
}
