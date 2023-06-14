#include <stdio.h>
#include <stdlib.h>
#define maLO_size 10
#define in 30
int main(void)

{
char LO[maLO_size],input[in];
int A,B;
int pass, x=10;

	while (x!=0)
	{
	printf("\nInput the password: ");
	scanf("%d",&pass);

	if (pass==1234)
	{
		printf("Correct password");
		 printf("Enter THE Product Code(ALL CAPTIAL PLEASE !!):");
        scanf("%s",input);
for(A=0; !(input[A]>='0' && input[A]<='9'); ++A){}

        strncpy(LO,input,A);
                LO[A]='\0';
        printf("Warehouse:%s\n",LO);
for(B=A; input[B] < 'A' || input[B] > 'Z'; ++B){}

            strncpy(LO,&input[A],B - A);
                        LO[B - A]='\0';
                                printf("Product:%s\n",LO);
                                printf("Qualifiers:%s\n",&input[B]);
		x=0;
    }
    else
    {
       printf("Wrong password, try another");
	}
	printf("\n");
   }



return 0;

}
