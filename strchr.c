#include <stdio.h>
 
#define      ARRAY_SIZE      100
 
char *strchr(const char *str, int ch)
{
   int k;
 
   for (k = 0; str[k] != '\0'; ++k)
      if (str[k] == ch)
         return (char *)(str + k);
 
   return NULL;
}
 
int main()
{
   char s[ARRAY_SIZE];
   int ch;
   char *ptr;
 
   printf("bir yazi giriniz : ");
   gets(s);
 
   printf("aranacak karakter : ");
   ch = getchar();
 
   ptr = strchr(s, ch);
 
   if (!ptr)
      printf("(%s) yazisinda (%c) karakteri yok!\n", s, ch);
   else
      printf("bulundu = (%s)\n", ptr);
 
   return 0;
}

