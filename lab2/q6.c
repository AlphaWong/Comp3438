#include <sys/types.h>

#include <sys/stat.h>

#include <fcntl.h>

#include <unistd.h>

#include <stdio.h>

void main()

{

  int myfd;
  int bytesread;

  pid_t childpid;

  char buf[80];

  if ((childpid = fork()) == -1)

    perror("Could not fork");

  else if ((myfd = open("my.dat", O_RDONLY)) == -1)

    perror("Could not open file");

  else if (childpid == 0)

  /* child code is here */

  {

    fprintf(stdout, "Child here - myfd is %d\n", myfd);

    bytesread = read(myfd, buf, 80);

    if (bytesread > 0)

      write(STDOUT_FILENO, buf, bytesread);

  }

  else

  /* parent code is here */

  {

    fprintf(stdout, "Parent here - myfd is %d", myfd);

    fprintf(stderr, "Why 'Parent here ...' written after this message? ");

    fprintf(stdout, "\n");

    bytesread = read(myfd, buf, 80);

    if (bytesread > 0)

      write(STDOUT_FILENO, buf, bytesread);
  }
}
