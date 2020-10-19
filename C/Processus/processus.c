#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	printf("Voici le PID de mon programme %d!\n",getpid());
	return 0;
}
