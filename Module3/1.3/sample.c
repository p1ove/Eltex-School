// #include <stdio.h>
// int main(int argc, char *argv[])
// {
// int i=0;
// printf("%s\n",argv[0]);
// printf("Args: ");
// while(argv[++i] != NULL)
// printf("%s ",argv[i]);
// return 0;
// }

#include <stdio.h>
#include <unistd.h>
int main(int argc, int *argv[])
{
printf("Run: %s", argv[0]);
execl("hello"," ","Hello", "World!", NULL);
execv("hello", argv);
return 0;
}