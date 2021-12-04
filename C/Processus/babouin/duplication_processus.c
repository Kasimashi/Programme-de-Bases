#include "stdio.h"
#include "stdlib.h"
#include <signal.h>
#include <unistd.h>

int ATTENTE_FILS = 0;

void childHandler(int sig)
{
    printf("Babouin pere fait signe au fils que c'est à son tour.\n");
    // The old style should install the handler again.
    signal(SIGUSR1, childHandler);
}

int main()
{
    pid_t val;
    // If not set this, we cann't the child's output.
    // The stdout stream is buffered, so will only display what's in the buffer after it reaches a newline (or when it's told to).
    setbuf(stdout, NULL);
    if ((val != fork())) { //parinte
        printf("Babouin pere commence a traverser liane\n");
        sleep(1);
        printf("Babouin pere a fini de traverser liane\n");
        signal(SIGUSR1, childHandler);
    } else {
        while (ATTENTE_FILS)
            printf("Babouin fils commence a traverser liane\n");
            sleep(2);
            printf("Babouin fils a fini de traverser liane\n");
            pause(); // The pause() function suspends the process until a signal is caught.
    }

    return 0;
}     
