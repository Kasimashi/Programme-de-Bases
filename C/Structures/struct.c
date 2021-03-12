#include <stdio.h>
 
int main()
{
	struct {
		char c;
		int i;
	} s;

	printf("s\t%p\ns.c\t%p\ns.i\t%p\n", &s, &s.c, &s.i);
	return 0;
}
