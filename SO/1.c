#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define MAX 10
#define ZWYKLY 1
#define WAZNY 2

//struktura bufora
struct buf_elem { 
    long mtype;
    int mvalue;
};

int main(){
    int msgid, i;
    struct buf_elem elem;
    
    msgid = msgget(45281, IPC_CREAT|IPC_EXCL| 0600); 
    printf("Próba otwarcia/utworzenia kolejki komunikatów \n");
    
    if (msgid == -1) { // jezeli istnieje zgodnie z IPC_EXCL nastąpi błąd
            msgid = msgget(45281, IPC_CREAT|0600); //pobierz MSGID
            printf("Utworzenie kolejki komunikatów \n");
        if(msgid == -1){
            perror("#ERROR! Utworzenie kolejki komunikatów \n");
            exit(2);
        }
    }
    if (msgid !=-1) { //jezeli otworzylismy kolejke
        elem.mtype = ZWYKLY;
        for(i = 0; i<MAX; i++){
            printf("Wysylanie zwyklego komunikatu \n");
            if (msgsnd(msgid, &elem, sizeof(elem.mvalue), 0) == -1) { //nadawanie
                perror("#ERROR! Wyslanie zwyklego komunikatu \n");
                exit(3);
            }
        }
    }
    for (i = 0;i < 10; i++){
        printf("Odbieranie komunikatu \n");
        if (msgrcv(msgid,&elem, sizeof(elem.mvalue), ZWYKLY, 0) == -1){ //odbior
            perror("#ERROR! Odebranie waznego komunikatu \n");
            exit(4);
        }
        elem.mvalue = i;
        elem.mtype = WAZNY;
        if(msgsnd(msgid, &elem, sizeof(elem.mvalue), 0) ==-1){ //nadawanie
            perror("#ERROR! Wyslanie waznego komunikatu \n");
            exit(5);
        }
    }
    printf("Program zakonczyl sie bez bledow! \n");
    exit (0);
    
}
