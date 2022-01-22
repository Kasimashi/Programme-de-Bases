#include <stdio.h>
#include <stdarg.h>

void
foo(char *fmt, ...)   /* '...' is C syntax for a variadic function */
{
   va_list ap;
   int d;
   char c;
   char *s;
   char temp;
   va_start(ap, fmt);
   /* Tant qu'on arrive pas à la fin de la chaine on la parse */
   while (*fmt)
	   if (*fmt == '%'){
		   switch (*++fmt)
		   {
		   case 's':              /* string */
			   s = va_arg(ap, char *);
			   printf("string %s\n", s);
			   break;
		   case 'd':              /* int */
			   d = va_arg(ap, int);
			   printf("int %d\n", d);
			   break;
		   case 'c':              /* char */
			   /* need a cast here since va_arg only
				  takes fully promoted types */
			   c = (char) va_arg(ap, int);
			   printf("char %c\n", c);
			   break;
		   }
	   }
	   else{
		   *fmt++;
	   }

   va_end(ap);
}

void main(void)
{
    foo("%s %d %c","Helloworld",2,'a');
}
