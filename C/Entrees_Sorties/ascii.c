//Cette fonction renvoi le code ascii du char rentré en argument

#include <stdio.h>
#include <ctype.h>

main() {
  char c;
  c = getchar();
  if (isascii(c)) {
    printf("Le code ASCII de %c est %d\n", c, (int)(c));
  }
  else {
    printf("Pas de code ASCII pour ce caractere\n");  
  }
}
