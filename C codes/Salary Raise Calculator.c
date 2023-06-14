#include <stdio.h>
#include <stdlib.h>
double raise(sal);
int main()
{
    int c=0;
    char ch;
    double sal,eng,r;
    FILE *input;
    input=fopen("salaries.txt","r");
    fscanf(input,"%lf",&sal);
    while((ch = getchar())!=EOF)
      putc(ch,input);
   }
   fclose(input);
    return 0;
}
double raise(sal){
double eng;
    if(500<=sal && sal <750){

            eng= sal*1.13;
                printf("your new salary : %lf\n",eng);
                printf("%lf * 1.13= %lf",sal,eng);


    }
    else if (750<=sal && sal <1000){
        eng= sal * 1.15;
                printf("your new salary : %lf\n",eng);
                printf("%lf * 1.15= %lf",sal,eng);
    }
        else if(1000 <= sal && sal<1250){
          eng=sal+1.17;
                printf("your new salary : %lf\n",eng);
                printf("%lf * 1.17= %lf",sal,eng);
        }
        else{
            eng=sal+1.25;
                printf("your new salary : %lf\n",eng);
                printf("%lf * 1.25= %lf",sal,eng);
        }
return eng;
}

