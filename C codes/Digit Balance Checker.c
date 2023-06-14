#include <stdio.h>
#include <stdlib.h>

int DigitSum(int n);
int DigitCount(int n);
int DigitBalance(int n);
int main()
{
int num,num1;

  printf("please enter 2 numbers\n");
  printf("numbers 1:\n");
  scanf("%d",&num);
  printf("number 2 :\n");
  scanf("%d",&num1);

  while(num<=num1){
    int as= DigitBalance(num);

  if(as==1){
      printf("%d\n",num);
      num=num+1;
  }
  else{
      num=num+1;
      continue;
  }
  }


    return 0;
}
int DigitBalance(int num){
    int answer=DigitSum(num);
    int answer1=DigitCount(num);

    if(answer==answer1)
      return 1;
    else
    return 0;
}


int DigitSum(int num){
     int digit=0;
     int oddSum=0;
     int evenSum=0;
     while (num > 0) {
   digit = num % 10;
   if (digit % 2 == 1){
     oddSum=oddSum+digit;

   }
   else {
       evenSum=evenSum+digit;
       }

   num /= 10;
   }

   if(evenSum==oddSum){
       return 1;
   }else{

       return 0;
   }
}

int DigitCount(int num){
     int digit=0;
     int nodd=0;
     int neven=0;
     while (num > 0) {
   digit = num % 10;
   if (digit % 2 == 1){
     nodd++;

   }
   else {
       neven++;

   }
   num /= 10;
   }

   if(neven==nodd){
       return 1;
   }else{

       return 0;
   }
}
