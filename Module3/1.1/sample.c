#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
pid_t pid;
int rv;
switch(pid = fork()) {
case -1:

perror("fork");
exit(EXIT_FAILURE);
case 0:
printf("\n0\n");
printf("CHILD: PID - %d\n", getpid());
printf("CHILD: PPID - %d\n", getppid());
exit(EXIT_SUCCESS);

default:
printf("\n1\n");
printf("PARENT: PID - %d\n", getpid());
printf("PARENT: CHILD PID - %d\n", pid);
wait(&rv);
printf("PARENT: RETURN STATUS FOR CHILD - %d\n", WEXITSTATUS(rv));
}

exit(EXIT_SUCCESS);
}