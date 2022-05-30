#include <stdio.h>

int main(int argc, char **argv)
{
    float input[3]; 
    fscanf (stdin, "%f %f %f", input, input+1, input+2);
    
    printf("Read String1 |%f|\n", input );
    printf("Read String2 |%f|\n", input+1 );
    printf("Read String3 |%f|\n", input+2 );
   
    fprintf(stdout,"%f %f %f", input, input+1, input+2);
	return 0;
}
