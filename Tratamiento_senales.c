#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
// Nueva versión explicado en clase:
void funcion(){
    int fd = open("practica2.txt", O_CREAT|O_RDWR, 0666);
    char mensaje[100] = "Soy el proceso P3 y he recibido el mensaje de P5\n";
    write(fd, mensaje, strlen(mensaje));
    close(fd);
}

void funcion2(){
    printf("He recibido una señal de mi proceso padre\n");
}

void funcion3(){
    char mensaje2[] = "Soy P6\n";
    write(1, mensaje2, strlen(mensaje2));
}

int main(void){
    int x = 0;
    printf("PADRE | PID: %d , PPID: %d . Var = %d\n", getpid(), getppid(), x);
    if (fork() == 0){
        x = 1;
        printf("HIJO | PID: %d , PPID: %d . Var = %d\n", getpid(), getppid(), x);
        exit(0);
    }
    if (fork() == 0){
        x = 1;
        printf("HIJO | PID: %d , PPID: %d . Var = %d\n", getpid(), getppid(), x);
        sleep(2);
        exit(0);
    }
    if (fork() == 0){
        x = 1;
        printf("HIJO | PID: %d , PPID: %d . Var = %d\n", getpid(), getppid(), x);
        signal(SIGUSR1, funcion);
        if (fork() == 0){
            x = 0;
            printf("NIETO | PID: %d , PPID: %d . Var = %d\n", getpid(), getppid(), x);
            sleep(1);
            kill(getppid(), SIGUSR1);
        }
        sleep(2);
        exit(0);
    }
    if (fork() == 0){
        printf("HIJO | PID: %d , PPID: %d . Var = %d\n", getpid(), getppid(), x);
        if (fork() == 0){
            printf("NIETO | PID: %d , PPID: %d . Var = %d\n", getpid(), getppid(), x);
            sleep(10);
            signal(SIGUSR1, funcion3);
            sleep(1);
            execl("/bin/ls", "ls", (char*)0);
        }
        sleep(2);
        exit(0);
    }

    while (wait(NULL) > 0);
    return 0;
}
