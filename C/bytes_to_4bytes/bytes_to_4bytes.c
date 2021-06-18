#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    int x = 0;
    unsigned char a[]="\xDE\xAD\xBE\xEF\xDE\xAD\xBE\xEF";
    
    printf("Addresse de x : %p Valeur de x : %d Addresse de a : %p Valeur de a: %x\n",&x,x,&a,a[0]);

    int j;
    for (j=0;j<strlen(a);j+=4){
        memcpy(&x,&a[j],4);
        printf("%X\n",x);
    }
}
