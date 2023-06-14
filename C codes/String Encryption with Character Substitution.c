#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char str[1000], rev[1000];
    int i=0, j=0, count = 0 ,x=0;


    printf("Enter String : ");
    gets(str);
    while (str[count] != '\0')
    {
        count++;
    }
    j = count - 1;

    for (i = 0; i < count; i++)
    {
        rev[i] = str[j];
        j--;
    }

    while(rev[x]!='\0')
    {
        if(rev[x]=='s')
        {
            rev[x]='$';
        }
        else if(rev[x]=='a')
        {
            rev[x]='@';
        }
        else if(rev[x]=='o')
        {
            rev[x]='0';
        }

        x++;
    }
x-1;
    printf("-------------------------------------");
    printf("\nString After encyrption:");
    printf("\n-------------------------------------\n");
    printf("%s",rev);
    return 0;
}


int encrypt(char[]){

}
