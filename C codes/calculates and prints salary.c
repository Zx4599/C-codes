#include <stdio.h>
#include <stdlib.h>
   /*
khalid sami
1193137
sec 4
*/
int calculate_salary(int basic_salary,int extraWorkingHours,int extraWorkingHoursCost,double taxRate,int monthInsuranceCost,int num);

void print_salary_info(int basic_salary,int extraWorkingHours,int extraWorkingHoursCost,double taxRate,int monthInsuranceCost,int num);

int main()

{
    int Gross_price,basic_salary,extraWorkingHours,extraWorkingHoursCost,monthInsuranceCost,num;
    double taxRate;
    FILE *in;

    in = fopen("salary_info.txt","r" );
    fscanf(in,"%d",&extraWorkingHoursCost);
    fscanf(in,"%lf",&taxRate);
    if(in==NULL)
{
    printf("file no working\n");
    return 0;
    fclose(in);
}
    printf("enter basic salary:\n");
    scanf("%d",&basic_salary);

    printf(" Enter extra working hours:\n");
    scanf("%d",&extraWorkingHours);

    printf("Do you have a medical insurance , 1 yes ,  2 no :\n");
    scanf("%d",&num);

    if(num==1)
{
    printf(" Enter the cost of the monthly insurance:\n");
    scanf("%d",&monthInsuranceCost);
}
   Gross_price=calculate_salary(basic_salary,extraWorkingHours,extraWorkingHoursCost,taxRate,monthInsuranceCost,num);
   print_salary_info(Gross_price,extraWorkingHoursCost,monthInsuranceCost,taxRate,num,basic_salary);
}
int calculate_salary(int basic_salary,int extraWorkingHours,int extraWorkingHoursCost,double taxRate,int monthInsuranceCost,int num)
{
    int Gross_price;

    Gross_price= basic_salary + (extraWorkingHours*extraWorkingHoursCost) - (basic_salary*taxRate);
    if(num==1)
{
    Gross_price= Gross_price - monthInsuranceCost;
}
    return Gross_price;
}
void print_salary_info(int gross_salary,int extra_working_hours,int insurance_cost,double taxrate,int num,int basic_salary )
{
    double TaxRate = basic_salary*taxrate;
   printf("\n \n  Salary Info:\n");
   printf("\n*** tax rate is =%d ***\n",(int)TaxRate);
   printf("\n*** number of extra working hours =%d ***\n",extra_working_hours);
   if(num==1)
{
   printf("\n*** insurance cost =%d ***\n",insurance_cost);
}
   printf("\n*** Gross salary =%d ***\n",gross_salary);

}
