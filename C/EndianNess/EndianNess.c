#include <stdio.h>
/* Can also be <netinet/in.h>  */
#include <arpa/inet.h> 

#define IS_BIG_ENDIAN (!*(unsigned char *)&(uint16_t){1})

int main() {
    long x = 0xC0A80101;
    printf("Basic value :\n0x%x\n", x);
    x = htonl(x);
    printf("After htonl()\n");
    printf("0x%x\n", x);
    x = ntohl(x);
    printf("After ntohl()\n");
    printf("0x%x\n", x);
}
