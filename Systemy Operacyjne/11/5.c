#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX 100
#define KEY 1234

int main(){
    int shmid, a,b,c;
    void *shared_memory = (void *)0;
    scanf("%d %d %d", a, b, c);
    if(fork() !=0) {
        shmid = shmget(KEY, MAX, 0666 | IPC_CREAT);
        shared_memory = shmat(shmid, NULL, 0);
        sprintf(shared_memory,"%d", a);
    }else {
        int pdesk;
        mkfifo("/tmp/fifo", 0666);
        read(pdesk,shared_memory, MAX);
        printf("%d", a);
        
    }
        exit(0);
    }
