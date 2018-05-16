#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
#define MAX 100
#define KEY 1234
 
 int main(){
     int shmid;
     void *shared_memory = (void *)0;
     shmid = shmget(KEY, MAX, 0666 |IPC_CREAT);
     shared_memory = shmat(shmid, NULL,0);
     sprintf(shared_memory, "Hello World");
    
 exit(0);
 }
