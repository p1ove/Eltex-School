#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <math.h>

// void print(int argc, char** argv){
//     for (int i = 1; i < argc/2; i++ ){
//         printf("%d\n",pow(atoi(argv[i]),2));
//     }
// }

int main(int argc, char** argv){

    pid_t pid;
    int rv;

    switch(pid = fork()){
        case -1:
            perror("fork");
            exit(EXIT_FAILURE);

        case 0:
            for (int i = argc; i > argc/2; i-- ){
                printf("%lf\n",pow(atoi(argv[i]),2));
            }            
            exit(EXIT_SUCCESS);

        default:
            for (int i = 1; i < argc/2; i++ ){
                printf("%lf\n",pow(atoi(argv[i]),2));
            }
            wait(&rv);
    }

    exit(EXIT_SUCCESS);
}

