#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define MAX 5
#define TYP1 1
#define TYP2 2

//struktura bufora 
struct buf_elem{
    long mtype;
    int mvalue;
};

int main(){
    int msgid, i;
    struct buf_elem elem;
    msgid = msgget(45281, IPC_CREAT|IPC_EXCL|0600);
    if(msgid == -1){ // jezeli istnieje
        msgid = msgget(45281, IPC_CREAT|0600); //pobierz MSGID
        printf("Utworzenie kolejki komunikatów \n");
        if (msgid == -1){
            perror("#ERROR! Utworzenie kolejki komunikatów \n");
            exit(1);
        }
    }
    if (msgid != -1) {//jezeli utworzylismy kolejke
        if(fork() == 0) { //podział na dwa procesy
            elem.mtype = TYP1;
            for ( i = 0; i < MAX ; i++){
                printf("Wysylanie komunikatu typu 1 \n");
                //nadawanie komunikatu TYP1
                if(msgsnd(msgid, &elem, sizeof(elem.mvalue),0) == -1){
                    perror("#ERROR! Wyslanie komunikatu \n");
                    exit(2);
                    
            }
        }
        elem.mtype = TYP2;
        for( i = 0; i <  MAX; i++){
            printf("Wysylanie  komunikatu typu 2 \n");
            //nadawanie komunikatu TYP2
            if(msgsnd(msgid, &elem, sizeof(elem.mvalue), 0) == -1){
                perror("#ERROR! Wyslanie komunikatu \n");
                exit(3);
                }
            }
        }
    }else{
        for(i = 0; i<MAX; i++){
            printf("Odbieranie komunikatu o typie 1 \n");
            //Odbieranie tylko komunikatu o typie TYP1
            if(msgrcv(msgid, &elem, sizeof(elem.mvalue),TYP1, 0) == -1){
                perror("#ERROR! Odebranie pustego komunikatu \n");
                exit(4);
            }
        }
    }
}else {
    perror("Błąd utworzenia kolejki");
    exit(5);
}
wait(NULL);

printf("Program zakonczyl sie bez bledow \n");
exit (0);
}
            
