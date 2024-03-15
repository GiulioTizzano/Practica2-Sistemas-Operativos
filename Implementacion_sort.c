#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <wait.h>
#include <fcntl.h>
#include <asm-generic/fcntl.h>

int main(void) {
    int fd;
    char string[20];
    // Aquí el usuario podrá introducir un cadena de palabras.
    printf("Introduzca un mensaje en minúsculas todo por favor: \n");
    fd = open("archivo.txt", O_RDWR | O_CREAT, 0666);
    scanf("%s", string);
    write(fd, string, strlen(string));

    for(int i = 0; i <= strlen(string); i++) {
        // algoritmo para la función para ordenar las palabras en orden alfabético.
    }



    


}