#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	int ifd, ofd, pipefd[2];
	
	printf("Process' File Descriptor Table \n");
	printf("---------------------------------------- \n");
	printf("Descriptor\t Pointer\t Description\n");
	printf("---------------------------------------- \n");
	printf("%d\t\t %p --------------> Terminal's Input Device \n", STDIN_FILENO, stdin);
	printf("%d\t\t %p --------------> Terminal's Output Device \n", STDOUT_FILENO, stdout);
	printf("%d\t\t %p --------------> Terminal's Error Device \n", STDERR_FILENO, stderr);
	
	/* Create two files, one input and one output */
	
	ifd = open("in.txt", O_RDONLY);
	ofd = open("out.txt", O_WRONLY);
	
	printf("%d\t\t %p --------------> File in.txt \n", ifd, fdopen(ifd,"r"));
	printf("%d\t\t %p --------------> File out.txt \n", ofd, fdopen(ofd,"w"));
	
	/* Create a pipe */
	
	pipe(pipefd);
	printf("%d\t\t %p --------------> Pipe's Read End \n", pipefd[0], fdopen(pipefd[0],"r"));
	printf("%d\t\t %p --------------> Pipe's Read End \n", pipefd[1], fdopen(pipefd[1],"w"));
	
	
}
