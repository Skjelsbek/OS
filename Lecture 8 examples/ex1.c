#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

void echo(char *txt)
{  
    printf("%s\n",txt);
    char chin,chout;
    chin = getchar();
    chout = chin;
    putchar(chout);
}

int main()
{

  pid_t pid[2];
  int status;
  char txt[64];
  
  pid[0] = fork();
  
  if (pid[0] == -1) {
    printf("Cannot fork\n");
    exit(1);
    }
   
  if (pid[0] == 0) {	//child    
    printf("process [%d] running...\n",getpid());  
    sprintf(txt,"In echo from [%d]",getpid());
    echo(txt);
    exit(0);
    } 

  pid[1] = fork();

  if (pid[1] == -1) {
    printf("Cannot fork\n");
    exit(1);
    }

  if (pid[1] == 0) {	//child    
    printf("process [%d] running...\n",getpid());  
    sprintf(txt,"In echo from [%d]",getpid());
    echo(txt);
    exit(0);
    } 

  printf("Parent process: waiting for child processess...\n");
  
  while (waitpid(pid[0],&status,WUNTRACED) == -1) {
    printf("Error wait!\n");
    exit(1);
    }

  while (waitpid(pid[1],&status,WUNTRACED) == -1) {
    printf("Error wait!\n");
    exit(1);
    }
    
  printf("Parent process: child finished. Exiting...\n");
}
