#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void main(int argc, char *argv[])

{

  int i;

  pid_t curpid = getpid();
  pid_t curppid = getppid();
  pid_t childpid;

  for (i = 0; i < 4; i++) {

    printf("i- %d ---;", i);
    childpid = fork();
    setpgid(curpid + i, curppid);

    if (childpid == 0)
      break;
  }

  printf("my child is %d, my ppid %d\n", getpid(), getppid());
}
