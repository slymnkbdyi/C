#include<stdio.h>
     
int main(void)
{
   
   char *i,*j;
   
   char str[30];
   
   printf("ENTER A STRING:--->\t",str);
   scanf("%s",&str);
          
   i=str;
          
   j=str;
   
   while(*j != '\0')
     j++;
     j--;
         
   while(j >= &str[0]){
       if(*i++ != *j--){
           printf("\n IT IS NOT A PALINDROM");
           exit(0);
       }   
      
   }
         printf("\n IT IS A PALINDROM");
   
   return 0;      
}
    
