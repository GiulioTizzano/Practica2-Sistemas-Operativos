#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <wait.h>

// Programa que ejecuta la jerarquía de procesos que se nos pide en el enunciado:
int main(void) {
    int variable;
    variable = 1;
    int rt;
    
    for(int i = 1; i <= 4; i++) {
        
        rt = fork();
        if(rt == 0) {
            if(i == 1 || i == 2) {
                printf("\n Soy el proceso %d y mi padre es %d \n y soy el proceso %d", getpid(), getppid(), variable);
                break;
            } 
           
            // else if(i == 3 || i == 4) {
            //     rt = fork();
            //     printf("\n Soy el proceso %d y mi padre es %d \n", getpid(), getppid());
            //     break;
            // }
            // Poner otro else if pero con i ==4
            
            else if(i == 3) {
                rt = fork();
                printf("\n Soy el proceso %d y mi padre es %d y mi número de proceso es %d\n", getpid(), getppid(), variable);
                break;
            } else if(i == 4) {
                rt = fork();
                printf("\n Soy el proceso %d y mi padre es %d \n", getpid(), getppid());
                execl("/bin/ls", "-l", (char*)0);
            }
        }
        variable++;
    }
    while(wait(NULL) > 0);
    return 0;
}
// b) Los procesos se ejecutan en un orden arbitrario ya que en cada ejecución varía.

// c) Se ha modificado el código de arriba para implementar la lógica
// del contador para el proceso P1, P2 y P3.
// d) Implementado en el código de arriba.









