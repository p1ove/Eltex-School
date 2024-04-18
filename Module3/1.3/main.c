#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>


int main(){

    pid_t pid;
    int rv;
    char string[30];
    char* argv[30] = {0};

    while (1){
        
        printf("# ");
    
        fgets(string, 100, stdin);// scanf("%s",string);

        char* sep;
        int cnt = 0;
        sep = strtok(string, " ");

         while (sep!=NULL){
            argv[cnt++] = sep;
            sep = strtok(NULL, " ");
        }

    switch(pid = fork() ){
        case -1:
            perror("fork");
            exit(EXIT_FAILURE);
        case 0:
            execv(argv[0], argv);  
            exit(EXIT_SUCCESS);
        default:
            wait(&rv);
    }
}
return 0;
}