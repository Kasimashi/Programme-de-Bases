// Program to calculate the sum of n numbers entered by the user

#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, i, *ptr, sum = 0;

  printf("Enter number of elements: ");
  scanf("%d", &n);

  ptr = (int*) malloc(n * sizeof(int));

  printf("Les éléments vont être stockés aux addresses:\n");
  for (i=0;i<n;++i){
	  printf("%p pour l'élément %d\n",ptr+i,i);
  }

  // if memory cannot be allocated
  if(ptr == NULL) {
    printf("Error! memory not allocated.");
    exit(0);
  }


  for(i = 0; i < n; ++i) {
	printf("Enter elements %d: ",i);
    scanf("%d", ptr + i);
    printf("Valeur lue à l'addresse %p :%d\n",ptr+i, *(ptr+i));
    sum += *(ptr + i);
  }

  printf("La somme vaut : = %d\n", sum);

  // deallocating the memory
  free(ptr);

  return 0;
}
