#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define KLUCZ 43281

struct buf_elem {
    long mtype;
    char mtext[6];
};

int main(){
    int msgid, i;
    struct buf_elem buf;
    
    msgid = msgget(KLUCZ, IPC_CREAT|0600);
    
    if(fork() == 0){ //proces potomny
        struct buf_elem buf;
        buf.mtype = 1;
        sprintf(buf.mtext, "Hallo!");
        msgsnd(msgid, &buf, sizeof(buf.mtext), 0);
    } else { //proces macierzysty
        struct buf_elem buf;
        msgrcv(msgid, &buf, sizeof(buf.mtext), 1, 0);
        printf("Odebrano komunikat: %s \n",buf.mtext);
    }
    exit (0);
}
