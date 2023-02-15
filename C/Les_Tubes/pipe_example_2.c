#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(void)
{
  int status1, status2;
  int pid1, pid2;
  int pip[2];
  char *argexec1[] = {"/bin/grep", "bash", NULL};
  char *argexec2[] = {"/bin/ps", "aux", NULL};

  if (pipe(pip) == -1){
    perror("pipe error \n");
    exit(1);
  }

  if ((pid1 = fork()) == -1){
    perror("fork error");
    exit(1);
  }

  if (pid1 == 0) {

    // Child process#1

    dup2(pip[0], 0);
    close(pip[1]);
    close(pip[0]);

    execvp("grep", argexec1);
    perror("exec1 failed\n");
    _exit(2);

  } else {

    // Father process

    if ((pid2 = fork()) == -1){
      perror("fork error");
      exit(1);
    }

    if (pid2 == 0) {

      // Child process#2

      dup2(pip[1], 1);
      close(pip[1]);
      close(pip[0]);

      execvp("ps", argexec2);
      perror("exec2 failed\n");
      _exit(2);
    
    } else {

      // Father process

      close(pip[0]);
      close(pip[1]);

      // Wait for the end of the programs
      if (-1 == waitpid(pid1, &status1, 0)) {
        perror("wait1 error");
        exit(1);
      }
      if (-1 == waitpid(pid2, &status2, 0)) {
        perror("wait2 error");
        exit(1);
      }

      // Return the exit code of the last program in the pipe
      if (WIFEXITED(status1)) {
        return WEXITSTATUS(status1);
      } else {
        // The process may have received a signal, return the whole status...
        return status1;
      }

    }

  }

  return 0;
}
