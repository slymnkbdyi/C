#include <stdio.h>

#define IN 1 /* kelime icinde */
#define OUT 0 /* kelime disinda */

/* satir,kelime ve karakter sayici */
int main()
{
  int c, n_satir, n_kelime, n_karakter, state;
  
  state = OUT;
  n_satir = n_kelime = n_karakter = 0;
  while ((c = getchar()) != EOF) {
    ++n_karakter;
    if (c == '\n')
      ++n_satir;
    if (c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++n_kelime;
    }
  }
  printf("%d %d %d\n", n_satir, n_kelime, n_karakter);
  return 0;
}
