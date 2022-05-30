/* 
     pipeline.c : create the pipeline 

                  who | cut -f1 -d' ' | uniq

*/

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <error.h>

int main (int argc, char **argv) 
{
    int pfd1 [2], pfd2 [2];
    pid_t pid1, pid2, pid3;

    if (pipe (pfd1) == -1)
       perror ("pipe");
    
    pid1 = fork ();

    if (pid1 == 0) {
        // first child, will become "who"
        if (dup2 (pfd1 [1], STDOUT_FILENO) == -1)
            perror ("dup2");
        if (close (pfd1 [0]) == -1)
            perror ("close");
        if (close (pfd1 [1]) == -1)
            perror ("close");
        execlp ("who", "who", (char *) NULL);
        perror ("execlp");
    }
    
    /* parent process */
    if (pipe (pfd2) == -1)
       perror ("pipe");

    pid2 = fork ();

    if (pid2 == 0) {
        // second child, who will become "cut"
        if (dup2 (pfd1 [0], STDIN_FILENO) == -1)
            perror ("dup2");
        if (dup2 (pfd2 [1], STDOUT_FILENO) == -1)
            perror ("dup2");
        if (close (pfd1 [0]) == -1)
            perror ("close");
        if (close (pfd1 [1]) == -1)
            perror ("close");
        if (close (pfd2 [0]) == -1)
            perror ("close");
        if (close (pfd2 [1]) == -1)
            perror ("close");
        execlp ("cut", "cut", "-f1", "-d ", (char *) NULL);
        perror ("execlp");
    }
    
    /* parent process */
    
    if (close (pfd1 [0]) == -1)
        perror ("close");
    if (close (pfd1 [1]) == -1)
        perror ("close");

    pid3 = fork ();

    if (pid3 == 0) {
        // third child, who will become "uniq"
        if (dup2 (pfd2 [0], STDIN_FILENO) == -1)
            perror ("dup2");
        if (close (pfd2 [0]) == -1)
            perror ("close");
        if (close (pfd2 [1]) == -1)
            perror ("close");
        execlp ("uniq", "uniq", (char *) NULL);
        perror ("execlp");
    }

    /* parent process */

    if (close (pfd2 [0]) == -1)
        perror ("close");
    if (close (pfd2 [1]) == -1)
        perror ("close");

    if (waitpid (pid1, NULL, 0) == -1)
         perror ("waitpid");
 
    if (waitpid (pid2, NULL, 0) == -1)
         perror ("waitpid");
    
    if (waitpid (pid3, NULL, 0) == -1)
         perror ("waitpid");
}
