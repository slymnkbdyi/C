include <stdio.h>
#include <stdlib.h>
#include <time.h>

char** fSplitStr(char *str, const char *delimiters)
{
    char * token; 
    char **tokenArray;
    int count=0;
    token = (char *)strtok(str, delimiters); // Get the first token
    tokenArray = (char**)malloc(1 * sizeof(char*));

    if (!token) {       
        return tokenArray;  
} 

    while (token != NULL ) { // While valid tokens are returned     
        tokenArray[count] = (char*)malloc(sizeof(token));
        tokenArray[count] = token;
        printf ("%s", tokenArray[count]);    
        count++;
        tokenArray = (char **)realloc(tokenArray, sizeof(char *) * count);      
        token = (char *)strtok(NULL, delimiters); // Get the next token     
} 
    return tokenArray;
}

int main (void)
{
    char str[] = "Split_The_String";
    char ** splitArray = fSplitStr(str,"_");
    printf ("%s", splitArray[0]);
    printf ("%s", splitArray[1]);
    printf ("%s", splitArray[2]);
    return 0;
}
