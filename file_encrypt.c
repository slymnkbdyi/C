/* by ftastemur */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define      MAX_FILE_NAME_LEN      80
 
int main(int argc, char **argv)
{
   char source_file_name[MAX_FILE_NAME_LEN + 1];
   char dest_file_name[L_tmpnam];
   int key, ch;
   FILE *fsource, *fdest;
 
   if (argc != 2) {
      printf("sifrelenecek dosyanin ismini giriniz : ");
      gets(source_file_name); 
      printf("anahtar degerini giriniz : ");
      scanf("%d", &key);
   }
   else {
      strcpy(source_file_name, argv[1]);
      key = atoi(argv[2]);
   }
 
   tmpnam(dest_file_name);
 
   fsource = fopen(source_file_name, "rb");
   if (fsource == NULL) {
      fprintf(stderr, "%s dosyasi acilamiyor!\n", source_file_name);
      exit(EXIT_FAILURE);
   }
 
   fdest = fopen(dest_file_name, "wb");
   if (fdest == NULL) {
      fprintf(stderr, "%s dosyasi yaratilamiyor!\n", source_file_name);
      fclose(fsource);
      exit(EXIT_FAILURE);
   }
 
   srand(key);
 
   while ((ch = fgetc(fsource)) != EOF)
      fputc(ch ^ rand(), fdest);
 
   fclose(fsource);
   fclose(fdest);
 
   remove(source_file_name);
   rename(dest_file_name, source_file_name);
 
   return 0;
}


