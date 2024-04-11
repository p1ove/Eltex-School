#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void print(int argc, char** argv){
    for (int i = 1; i < argc; i++ ){
        printf("%s\n",argv[i]);
    }
}

int main(int argc, char** argv){

    pid_t pid;
    int rv;

    switch(pid = fork()){
        case -1:
        perror("fork");
        exit(EXIT_FAILURE);

        case 0:
        print(argc,argv);
        exit(EXIT_SUCCESS);
        
        default:
        print(argc,argv);
        wait(&rv);
    }

    exit(EXIT_SUCCESS);
}

