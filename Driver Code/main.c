#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"functions.h"
char x[30];
char del_name[30];
int count = 0;
struct phbook
{
char name[30];
char sex;
char fname[30];
long int ph_no;
long int adhar_no;
char email[30];
}user_data[10];

int main()
{  system("color F2");
   int input;
   while(1)
   {
    options();
    scanf("%d",&input);
    system("cls");
    printf("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    if(input == 1)
     {
      add();
     }
    else if(input == 2)
     {
      list ();
     }
    else if(input == 3)
     {
      search();
     }
    else if(input == 4)
     {
      del_record();
     }
    else if(input == 5)
     {
       system("color 2F");
       printf("\n\t\tThank You");
      return 0;
     }
    else
     {
      printf("Please enter valid option\n");
     }
   }
}

void options() {
     printf("------------------------------------------------------\n");
     printf("\t***** PhoneBook Application *****");
     printf("\n------------------------------------------------------\n");
	 printf("\t> Add a New Record (press 1)\n");
	 printf("\t> List all the Records (press 2)\n");
	 printf("\t> Search for a Record (press 3)\n");
	 printf("\t> Delete a Record (press 4)\n");
	 printf("\t> To Quit the Application (press 5)\n");
     printf("------------------------------------------------------\n");
     printf("Enter your choice : ");
 }

void add() {
    FILE *f = f=fopen("contacts.txt","a+");
    static int i=0;
    printf("\nEntering a New Record %d\n",i+1);

    fflush(stdin);
    printf("\nEnter the Name : ");
    fgets(user_data[i].name,30,stdin);
    fprintf(f,"name : %s",user_data[i].name);

    fflush(stdin);
    printf("\nEnter the Gender (M/F) : ");
    scanf("%c",&user_data[i].sex);
    fprintf(f,"Gender : %c",user_data[i].sex);

    fflush(stdin);
    printf("\nEnter Father's Name : ");
    fgets(user_data[i].fname,30,stdin);
    fprintf(f,"\nFather's name : %s",user_data[i].fname);

    fflush(stdin);
    printf("\nEnter the Phone Number : ");
    scanf("%ld",&user_data[i].ph_no);
    fprintf(f,"%ld",user_data[i].ph_no);

    fflush(stdin);
    printf("\nEnter Aadhar Number : ");
    scanf("%ld",&user_data[i].adhar_no);
    fprintf(f,"\nphone no. : %ld",user_data[i].adhar_no);

    fflush(stdin);
    printf("\nEnter Your Email :");
    fgets(user_data[i].email,30,stdin);
    fprintf(f,"\nEmail : %s\n\n",user_data[i].email);

    fflush(stdin);
    printf("\nContact Saved :) \n");
    fclose(f);
    i++;
    count++;
    printf("\nPress Any Character : ");
    scanf("%s",x);
    system("cls");
}

void list()
{
    printf("\n\tPrinting all the Contacts : \n");
    int i;
    for(i=0;i<count;i++)
      {
      if(user_data[i].name == del_name) {
        continue;
      }
      else 
      {
     printf("\nName : %s\nGender : %c\nFather's Name : %s\nPhone No. : %ld\nAadhaar no. : %ld\nEmail : %s\n\n",user_data[i].name,user_data[i].sex,user_data[i].fname,user_data[i].ph_no,user_data[i].adhar_no,user_data[i].email);
      }
    }
  printf("\nPress Any Character : ");
    scanf("%s",x);
    system("cls");
}

void search()
{
  char name_temp[20];
  fflush(stdin);
  printf("\nEnter Name you want to search : ");
  fgets(name_temp,20,stdin);
  int  i;
  for( i=0; i<count;i++)
  {
    if(strstr(user_data[i].name,name_temp))
    {
      printf("\nName : %s\nGender : %c\nFather's Name : %s\nPhone No. : %ld\nAadhaar no. : %ld\nEmail : %s\n\n",user_data[i].name,user_data[i].sex,user_data[i].fname,user_data[i].ph_no,user_data[i].adhar_no,user_data[i].email);
   
    }
  }

  if(!strstr(user_data[1].name,name_temp)&& !strstr(user_data[2].name,name_temp) && !strstr(user_data[3].name,name_temp) && !strstr(user_data[4].name,name_temp) && !strstr(user_data[5].name,name_temp) && !strstr(user_data[6].name,name_temp) && !strstr(user_data[7].name,name_temp) && !strstr(user_data[8].name,name_temp) && !strstr(user_data[0].name,name_temp) && !strstr(user_data[9].name,name_temp) )
    {
     printf("\nThere is no such entry :(\n");
    }
 printf("\nPress Any Character : ");
    scanf("%s",x);
    system("cls");
}

void del_record()
{
  char name_temp[20];

  fgets(name_temp,20,stdin);
  printf("\nEnter Name you want to Delete : ");
  fgets(name_temp,20,stdin);
  strcpy(del_name,name_temp);
  //strcpy(del_name[count],name_temp);

  FILE *f,*fb;
  f = fopen("contacts.txt","r");

  if(count == 0)
  {
    printf("\nNo data present\n");
  }
  fb = fopen("temp.txt","a+");


    int i=0,file_data;
    while(fread(&user_data[i],sizeof(user_data[i]),1,f)==1)
        {
         if(!strstr(user_data[i].name,name_temp))
            fwrite(&user_data[i],sizeof(user_data[i]),1,fb);
         if(strstr(user_data[i].name,name_temp))
            file_data=1;
        }

     fclose(f);
     fclose(fb);
    if(file_data!=1)
      {
       printf("\nNo Contacts Recorded to Delete\n");
      }
    else
    {
        remove("contacts.txt");
        rename("temp.txt","contacts.txt");
        printf("\n\nRecord Deleted Successfully !!\n");
         int j;
         for( j=0;j<10;j++)
        {
          if(strstr(user_data[j].name,name_temp))
           {
             while(strstr(user_data[j].name,name_temp))
             {  
               user_data[j]=user_data[j+1];
             }
           }
        }

      }
    count--;
    printf("\nPress Any Character : ");
    scanf("%s",x);
    system("cls");
}

