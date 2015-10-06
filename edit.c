/* paragraf formatlama */

#include <stdio.h>
#include <string.h>
 
 
#define LINE_SIZE 50
 
void to_file(FILE *f, char *str);
char *rtrim(char *str);
char *get_word(FILE *f, char *str);
 
int main(void)
{
   FILE *in_file;
   FILE *out_file;
   char in_file_name[80] = "alone.txt";
   char out_file_name[80] = "ftastemur.txt";
   char buf[255] = {'\0'};
   char word[255] = {'\0'};
 
   printf("input file: ");
   gets(in_file_name);
   in_file = fopen(in_file_name, "r");
   if (in_file == NULL) {
      printf("can not open file: %s\n", in_file_name);
      return 0;
   }
 
   printf("output file: ");
   gets(out_file_name);
   out_file = fopen(out_file_name, "w");
   if (out_file == NULL) {
      printf("can not open file: %s\n", out_file_name);
      return 0;
   }
 
   while (get_word(in_file, word) != NULL) {
      if (strlen(buf) + strlen(word) > LINE_SIZE)
         to_file(out_file, buf);
      strcat(buf, word);
      while (buf[strlen(buf) - 1] == '\n')
         to_file(out_file, buf);
   }
   return 0;
}
/************************************/
char *get_word(FILE *f, char *str)
{
   int ch, i = 0;
   char *p = str;
 
   ch = fgetc(f);
   while (ch != EOF) {
      *p++ = ch;
      if (ch == ' ' || ch == '\n' || ++i > LINE_SIZE)
         break;
      ch = fgetc(f);
   }
   *p = '\0';
   if (*str == '\0')
      return NULL;
   return str;
}
/*************************************/
void to_file(FILE *f, char *buf)
{
   char residue[255] = "";
   char *p, *q;
   int flag;
 
   if (*buf == '\0')
      return;
 
   if (strlen(buf) <= LINE_SIZE && buf[strlen(buf) - 1] == '\n') {
      fputs(buf, f);
      *buf = '\0';
      return;
   }
 
   if (strlen(buf) > LINE_SIZE) {
      p = buf + LINE_SIZE;
      q = residue;
      while (*p != '\0')
         *q++ = *p++;
      *q = '\0';
      buf[LINE_SIZE] = '\0';
   }
   else {
      rtrim(buf);
      p = buf + strlen(buf) - 1;
      flag = 0;
      while (strlen(buf) < LINE_SIZE) {
         if (*p == ' ') {
            q = buf + strlen(buf) + 1;
            while (p < q) {
               *q = *(q - 1);
               q--;
               flag = 1;
            }
         }
         p--;
         if (p == buf)
            if (flag == 1)
               p = buf + strlen(buf) - 1;
            else
               break;
      }
   }
 
   fputs(buf, f);
   fputc('\n', f);
   strcpy(buf, residue);
   return;
}
/*************************************/
char *rtrim(char *str)
{
   char *p = str + strlen(str) - 1;
 
   while (*p == ' ')
      *p-- = '\0';
   return str;
}

/**************************************/
