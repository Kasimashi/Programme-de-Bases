#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    int x = 0;
    unsigned char a[]="\xDE\xAD\xBE\xEF\xDE\xAD\xBE\xEF";

    int j;
    for (j=0;j<strlen(a);j+=4){
        memcpy(&x,&a[j],4);
        printf("%X\n",x);
    }
}
