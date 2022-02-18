#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
int main(void){

 //La fonction fork renvoi un identificateur de processus
 //Il identifie le contexte dans lequel le processus s'execute
    int status;
    pid_t killReturnValue, forkReturnValue;

    if((forkReturnValue=fork())<0){
        //Lorsqu'il y'a une erreur.
        printf("Danger! Danger!\n");
        exit(EXIT_FAILURE);
    }

    if(forkReturnValue==0){
        sleep(100);
        exit(EXIT_SUCCESS);
    } else {
        killReturnValue = kill(forkReturnValue, SIGKILL);
        if(killReturnValue){
            printf("Impossible de tuer le processus enfant.\n");
            waitpid(forkReturnValue, &status, 0);
        } else {
            printf("Le processus enfant est tuer avec succes.\n");
        }
    }

    return 0;
}