#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int i=1;
   char words [15][19];
   char meaning [15][19];
   printf("please enter a sentence less than 10 words (less than 99 character ) :\n");
   FILE *input ;
   input  = fopen("translate.txt","r");
   int status = fscanf(input , "%s%s",words[0],meaning[0]);
   while ( status != EOF)
   {
    int i  ;
    status = fscanf(input ,"%s%s",&words[i],&meaning[i]);
    printf("%s  \t %s \n ",words[i],meaning[i]);
    i++ ;
   }


    return 0;
}
