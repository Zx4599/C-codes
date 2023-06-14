#include <stdio.h>
#include <stdlib.h>
//khalid sami 1193137 assi 1
int main()
{
    int binary, decimal = 0, num = 1, out;
  FILE* INPUT = fopen("binary.txt", "r");
    if(INPUT == NULL) //if the file is empty or not found
    {
        printf("Error file not found or empty >>>> check the file<<<<\n"); //it will print error
        exit(1);
    }
            fscanf(INPUT, "%d",&binary); // must be (0s and 1s)
        fclose(INPUT);

    int temp = binary;
    while(temp > 0)
    {
        out = temp % 10; /* divide the binary number by 10 and store the out in rem variable. */
        decimal = decimal + out * num;
        temp = temp / 10; // divide the number with quotient
        num = num * 2;
    }

    printf("The Binary Value  = %d\n", binary); // print the binary number
    printf("The Decimal Value = %d\n", decimal); // print the decimal

    FILE* deci = fopen("decimal.txt", "w");
            fprintf(deci, "%d",decimal);
        fclose(deci);


    return 0;
}
