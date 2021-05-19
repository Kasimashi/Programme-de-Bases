#include <stdio.h>
#include <string.h>


void swap(char *c1, char* c2);
void perm(char *s,int a, int n);


void main(int argc, char **argv)
{
    char str[10];
    int n;
    printf("Enter the String :\n");
    scanf("%s",str);
    n = strlen(str);
    printf("All Possible permutations :\n");
    perm(str,0,n-1);
}

void perm(char *s,int a, int n)
{
    int j;
    if(a==n)
        printf("%s\n",s);
    else{
        for(j=a;j<=n;j++){
            swap((s+a),(s+j));
            perm(s,a+1,n);
            swap((s+a),(s+j)); //backtracking
        }  
    }    
}

void swap(char *c1, char* c2){
    char temp;
    temp = *c1;
    *c1 = *c2;
    *c2=temp;

}
