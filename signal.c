#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <fcntl.h>
#include <stdlib.h>
static void sighandler(int signo){
  if (signo == SIGINT){
    int i;
    i  = open("out.txt",O_CREAT|O_RDWR|O_APPEND,0644);
    char a[] = "exit due to sigint\n";
    write(i,a,sizeof(a));
    exit(1);
  }
  else if (signo == SIGUSR1){
    printf("%d is the ppid\n", getppid());
  }
}
int main(){
  signal(SIGINT, sighandler); signal(SIGUSR1,sighandler);
  while(1){
    printf("hello my pareedtnt pid ios %d || mine is %d\n", getppid(),getpid());
    sleep(1);
  }
  return 0;
}
