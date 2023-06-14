#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include<math.h>
#include <windows.h>


struct student{
    char ID[15];
    char name[20];
    char reg[4];
    long unsigned int phone_no;
};


struct student stu;



void print_heading(const char st[]){
}

int conf_record(char id[]){

}


void add_student(){

    print_heading("Add Record");
    int print = 37;
    FILE *fp;
    fp = fopen("student.txt","ab+");
    if(fp == NULL){
        MessageBox(0,"Error in Opening file\nMake sure your file is not write protected","Warning",0);

    }else{
        fflush(stdin);
       printf("ID:");gets(stu.ID);
      printf("Name: ");gets(stu.name);
      printf("register year: ");scanf("%d",&stu.reg);
        printf("Phone Number: ");scanf("%ld",&stu.phone_no);
        fwrite(&stu, sizeof(stu), 1, fp);
         printf("The record is sucessfully added\n");
    }
    fclose(fp);
    return;
}

void search_student(){

    print_heading("Search Record\n");
    char s_id[15];
    int isFound = 0;
  printf("Enter ID to Search: \n");fflush(stdin);
    gets(s_id);
    FILE *fp;
    fp = fopen("student.txt","rb");
    while(fread(&stu,sizeof(stu),1,fp) == 1){
        if(strcmp(s_id,stu.ID) == 0){
            isFound = 1;
            break;
        }
    }
    if(isFound == 1){
       printf("The record is Found\n");
        printf("ID: %s\n",stu.ID);
      printf("Name: %s\n",stu.name);
     printf("register year: %d\n",stu.reg);
     printf("Phone No: %ld\n",stu.phone_no);
    }else{
    printf("Sory, No record found in the database\n");
    }
    fclose(fp);
    return;
}

void mod_student(){
    print_heading("Modify Record");
    char s_id[15];
    int isFound = 0, print = 37;
    printf("Enter ID to Modify:\n ");fflush(stdin);
    gets(s_id);
    FILE *fp;
    fp = fopen("student.txt","rb+");
    while(fread(&stu, sizeof(stu),1,fp) == 1){
        if(strcmp(s_id, stu.ID) == 0){
            fflush(stdin);
           printf("ID:\n ");gets(stu.ID);
          printf("Name: \n");gets(stu.name);
           printf("register: \n");scanf("%d",&stu.reg);
           printf("Phone Number: \n");scanf("%ld",&stu.phone_no);
            fseek(fp,-sizeof(stu), SEEK_CUR);
            fwrite(&stu,sizeof(stu), 1, fp);
            isFound = 1;
            break;
        }
    }
    if(!isFound){
        printf("No Record Found\n");
    }
    fclose(fp);
    return;
}

void gen_marksheet(){

}

void delete_student(){
    print_heading("Delete Record");
    char s_id[15];
    int isFound = 0, print = 37;
    printf("Enter ID to Modify: \n");fflush(stdin);
    gets(s_id);
    FILE *fp, *temp;
    fp = fopen("student.txt","rb");
    temp = fopen("temp.txt", "wb");
    while(fread(&stu, sizeof(stu),1,fp) == 1){
        if(strcmp(s_id, stu.ID) == 0){
            fwrite(&stu,sizeof(stu),1,temp);
        }
    }
    fclose(fp);
    fclose(temp);
    remove("student.txt");
    rename("temp.txt","record.txt");
    printf("\nThe record is sucessfully deleted\n");
    return;
}
void main(){


    int choice;
    int x = 2;
    while(1){
                printf("#---WELCOME TO THE MAIN MENU--##\n\n");
        printf("select a operation 1-6\n");
        printf("1- Create a new account.\n");
        printf("2- Check the details of existing account.\n");
        printf("3- Update information of existing account.\n");
        printf("4- Show all students list.\n");
        printf("5- Remove account.\n");
        printf("6. To Exit\n");
        printf("Enter your choice:\n\n ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                add_student();
                break;
            case 2:
                search_student();
                break;
            case 3:
                mod_student();
                break;
            case 4:
                break;
            case 5:
                delete_student();
                break;
            case 6:
                break;
            case 7:
                exit(0);
                break;
            default:
                break;
        }

    }



    return 0;
}


