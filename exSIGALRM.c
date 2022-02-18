#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void sig_alarm(int signo)
{           
    return; /*Réveille le pause */ 
}

void sleep1(unsigned nsecs)
{
    if (signal(SIGALRM, sig_alarm) == SIG_ERR){ /* On rendre l'action du SIGALRM vide */
        printf("Erreur lors l'association de handler sig_alarm à SIGALRM.\n");
        exit(EXIT_FAILURE);
    } 
    alarm(nsecs);     /* Initialiser un minuteur */ /* c'est une fonction non bloquant */
    pause();          /* Mettre le programme en attente d'un signal */ /* c'est une fonction bloquant */
                      /* Poursuite la programme après réception d'un signal */ 
}

int main()
{
    printf("Attente de 10 secondes\n");
    sleep1(10);
    printf("Fin du traitement\n");
    return 0;
}