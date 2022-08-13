//PROJECT TITLE:OPEN SOURCE CONTACT MANAGEMENT SYSTEM
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include"data.h"
#include"search.h"

void main(){
  void add_contact();   //prototype
  void list_contacts();
  void delete_contact();
  void edit_contact();
  void search_contact();
  void change_password();
 char pass[30],ch,original[30];
 int i,choice;
 FILE *fp;
 window(1,1,80,25);
 textbackground(YELLOW);
 clrscr();
 window(20,10,60,15);
 textbackground(BLACK);
 clrscr();
 gotoxy(4,3);
 textcolor(RED+BLINK);
 cprintf("Enter the Password:");
 i=0;
 while(1){
  ch=getch();
  if(ch==13) //ASCII CODE OF ENTER KEY
  { pass[i]='\0';
  break;
  }
  pass[i++]=ch;
  printf("*");
 }
// printf("\n You Entered %s",pass);
 //Reading data from the file
 fp=fopen("password.dat","r");
 fgets(original,30,fp);
 fclose(fp);
 if(!strcmp(original,pass)==0){
  gotoxy(4,5);
  textcolor(WHITE+BLINK);
  cprintf("Incorrect Password");
  printf("\nPress any key...");
  getch();
  exit(0);
 }
 else{
  window(1,1,80,25);
  textbackground(11);
  clrscr();
  gotoxy(20,3);
  textcolor(RED);
  cprintf("OPEN SOURCE CONTACT MANAGEMENT SYSTEM");
  gotoxy(20,5);
  textcolor(BLUE);
  cprintf("Version No:1.0");
  gotoxy(20,7);
  textcolor(YELLOW);
  cprintf("Developed by:Ayesha_Arab,Archi_Saxena,Divyesh_Vadher");
  textcolor(RED);
  gotoxy(5,15);
  cprintf("Please wait");
  for(i=0;i<=50;i++){
   cprintf("%c",220);
   delay(200);
  }
 while(1)
 {
  textbackground(YELLOW);
  clrscr();
  window(20,5,60,20);
  textbackground(BLACK);
  clrscr();
  textcolor(11);
  gotoxy(16,2);
  cprintf("MAIN MENU");
  gotoxy(15,3);
  cprintf("-----------");
  textcolor(WHITE);
  gotoxy(12,5);
  cprintf("1. Add New Contact");
  gotoxy(12,6);
  cprintf("2. Delete Contact");
  gotoxy(12,7);
  cprintf("3. Edit Contact");
  gotoxy(12,8);
  cprintf("4. Search Contact");
  gotoxy(12,9);
  cprintf("5. List of all Contact");
  gotoxy(12,10);
  cprintf("6.Change Password");
  gotoxy(12,11);
  cprintf("7. Exit");
  gotoxy(5,12);
  cprintf("----------------------------------");
  gotoxy(12,14);
  textcolor(YELLOW+BLINK);
  cprintf("Enter your choice(1-7)?");
  choice=getche();
  switch(choice){
   case '1':
      add_contact();
      break;
   case '2':
       delete_contact();
       break;
   case '3':
       edit_contact();
       break;
  case '4':
     search_contact();
     break;
  case '5':
     list_contacts();
     break;
     case '6':
     change_password();
     break;
  case '7':
  exit(0);

  }
  getch();
 }//end of while
}
}
void change_password(){
 FILE *fp;
 char current[30],original[30],newpass[30],confirm[30];
 window(1,1,80,25);
 textbackground(WHITE);
 textcolor(BLUE);
 clrscr();
 printf("Change Password");
 printf("\n----------------------------------------------------");
 printf("\nEnter the Current Password:");
 gets(current);
 //Reading password from password.dat file
 fp=fopen("password.dat","r");
 fgets(original,30,fp);
 fclose(fp);
 if(strcmp(current,original)!=0)
 {
  printf("\nIncorrect Password,Press any key...");
  getch();
  return;
 }
 printf("\nEnter New Password:");
 gets(newpass);
 printf("\nRe-Enter Password:");
 gets(confirm);
 if(strcmp(confirm,newpass)!=0)
 {
  printf("\nNot match,Press any key");
  getch();
  return;
 }
 fp=fopen("password.dat","w");
 fprintf(fp,"%s",newpass);
 fclose(fp);
 printf("Successfully Updated,Press any key");
 getch();
 }
 int getsno()
 {
   FILE *fp;
   int n,size;
   fp=fopen("info.dat","rb");
   size=sizeof(cont);
   fseek(fp,-size,SEEK_END);
   fread(&cont,sizeof(cont),1,fp);
   n=cont.sno;
   fclose(fp);
   n++;
   return(n);
}
 void add_contact(){
      FILE *fp;
      window(1,1,80,25);
      textbackground(YELLOW);
      textcolor(11);
      clrscr();
      cprintf("Add New Contact\n");
      printf("----------------------------------------------------");
      fflush(stdin);
      cont.sno=getsno();
      printf("\nSerial No:%d",cont.sno);

      fflush(stdin);  //to clear input buffer
      printf("\nEnter Category(Friend/PG/Salesman/Customer/Student):");
      gets(cont.category);
      fflush(stdin);
      printf("Enter name:");
      gets(cont.name);
      fflush(stdin);
      printf("Enter Gender m/f:");
      scanf("%c",&cont.gender);
      fflush(stdin);
      printf("Enter Age:");
      scanf("%d",&cont.age);
      fflush(stdin);
      printf("Enter Address:");
      gets(cont.address);
      fflush(stdin);
      printf("Enter Phone No:");
      gets(cont.phone);
      fflush(stdin);
    //  printf("Enter email id:");
     // gets(cont.email);
      fflush(stdin);
      fp=fopen("info.dat","ab");
      fwrite(&cont,sizeof(cont),1,fp);
      fclose(fp);
      textcolor(WHITE+BLINK);
      cprintf("\n Successfully saved,Press any key....");
      getch();
 }
 //Delete Contact
 void delete_contact(){
  int n,found,choice;
  FILE *fp1,*fp2;
  window(1,1,80,25);
  textbackground(CYAN);
  textcolor(YELLOW);
  clrscr();
  printf("Delete Contact");
  printf("\n-----------------------------------------------");
  printf("\n Enter Serial No to be deleted:");
  scanf("%d",&n);
  fp1=fopen("info.dat","rb");
  found=0;
  while(fread(&cont,sizeof(cont),1,fp1)!=NULL)
  {
   if(cont.sno==n)
   {
     printf("\nCategory : %s",cont.category);
     printf("\nName: %s",cont.name);
     printf("\nGender: %c",cont.gender);
     printf("\nAge: %d",cont.age);
     printf("\nAddress: %s",cont.address);
     printf("\nPhone no: %s",cont.phone);
     printf("\n-------------------------------------");
     found=1;
     break;
   }
  }
  if(found==0){
    textcolor(RED+BLINK);
    printf("\n");
    cprintf("Not Found, Press and Key...");
    getch();
    fclose(fp1);
    return;
  }
  printf("\nDelete it y/n:");
  choice=getche();
 if(choice=='y' || choice=='Y')
 {
  rewind(fp1);
  fp2=fopen("temp.dat","wb");
  while(fread(&cont,sizeof(cont),1,fp1)!=NULL)
  {
   if(cont.sno!=n)
     fwrite(&cont,sizeof(cont),1,fp2);
  }
  fclose(fp1);
  fclose(fp2);
  remove("info.dat");
  rename("temp.dat","info.dat");
  textcolor(GREEN+BLINK);
  cprintf("\n");
  cprintf("Successfully deleted, Press any key...");
  getch();
  }
 }
 //Edit Contact
 void edit_contact(){
   FILE *fp;
   int n,pos,found;
   window(1,1,80,25);
   textcolor(YELLOW);
   textbackground(BLACK);
   clrscr();
   printf("Edit Contact\n");
   printf("---------------------------------------------------------\n");
   printf("Enter the Serial No. to be edited:");
   scanf("%d",&n);
   fp=fopen("info.dat","r+b");
   found=0;
   while(fread(&cont,sizeof(cont),1,fp)!=NULL)
   {
    if(cont.sno==n)
    {
     found=1;
     printf("\nCategory  : %s",cont.category);
     printf("\nName      : %s",cont.name);
     printf("\nGender    : %c",cont.gender);
     printf("\nAddress   : %s",cont.address);
     printf("\nAge       : %d",cont.age);
     printf("\nContact no: %s",cont.phone);
     break;
     }
 }//end of while
   if(found==0)
   {
      printf("\n");
      textcolor(RED+BLINK);
      cprintf("Not Found,Press any key...");
      fclose(fp);
      getch();
      return;
   }
    printf("\n\n Enter New Data\n");
      pos=ftell(fp);
      fseek(fp,pos-sizeof(cont),SEEK_SET);

      fflush(stdin);  //to clear input buffer
      printf("\nEnter Category(Friend/PG/Salesman/Customer/Student):");
      gets(cont.category);
      fflush(stdin);
      printf("Enter name:");
      gets(cont.name);
      fflush(stdin);
      printf("Enter Gender m/f:");
      scanf("%c",&cont.gender);
      fflush(stdin);
      printf("Enter Age:");
      scanf("%d",&cont.age);
      fflush(stdin);
      printf("Enter Address:");
      gets(cont.address);
      fflush(stdin);
      printf("Enter Phone No:");
      gets(cont.phone);
      fflush(stdin);
      fwrite(&cont,sizeof(cont),1,fp);
      fclose(fp);
      printf("\n");
      textcolor(RED+BLINK);
      cprintf("Successfully Updated,Press any key....");
      getch();

   }
 //List of Contact
 void list_contacts(){
  int i;
  FILE *fp;
  window(1,1,80,25);
  textbackground(WHITE);
  textcolor(BLUE);
  clrscr();
  gotoxy(32,1);
  printf("LIST OF CONTACTS");
  printf("\n");
  for(i=1;i<=80;i++)
     printf("-");
   gotoxy(1,3);
   printf("SNO");
   gotoxy(8,3);
   printf("CATEGORY");
   gotoxy(20,3);
   printf("NAME");
   gotoxy(36,3);
   printf("GENDER");
   gotoxy(46,3);
   printf("AGE");
   gotoxy(55,3);
   printf("ADDRESS");
   gotoxy(70,3);
   printf("PHONE");
   printf("\n");
   for(i=1;i<=80;i++)
     printf("-");
     fp=fopen("info.dat","rb");
     i=5;
     while(fread(&cont,sizeof(cont),1,fp)!=NULL){
	 gotoxy(1,i);
	 printf("%d",cont.sno);
	 gotoxy(8,i);
	 printf("%s",cont.category);
	 gotoxy(20,i);
	 printf("%s",cont.name);
	 gotoxy(36,i);
	 printf("%c",cont.gender);
	 gotoxy(46,i);
	 printf("%d",cont.age);
	 gotoxy(55,i);
	 printf("%s",cont.address);
	 gotoxy(70,i);
	 printf("%s",cont.phone);
     i++;
     }
     fclose(fp);
     textcolor(RED+BLINK);
     printf("\n");
     cprintf("Press any Key....");
  getch();
 }
 //Search Contact
 void search_contact(){
  char ch;
  window(1,1,80,25);
  textbackground(BLACK);
  textcolor(11);
  clrscr();
  textcolor(WHITE);
  cprintf("SEARCH OPTIONS");
  printf("\n");
  printf("-----------------------------------------------");
  printf("\n1 Search by Serial No:");
  printf("\n2 Search by Category:");
  printf("\n3 Search by Name:");
  printf("\n4 Search by Phone no:");
  printf("\n5 Back to Main Menu:");
  printf("\n----------------------------------------------");
  textcolor(YELLOW+BLINK);
  printf("\n");
  cprintf("\nEnter your choice?");
  ch=getche();
  switch(ch)
  {
    case '1':
    search_sno();
    break;

    case '2':
    search_category();
    break;
    case '3':
      search_name();
      break;
    case '4':
      search_phone();
      break;
    case '5':
    return;
  }//end of switch
 }

