void search_sno()
{
 int n,found;
 FILE *fp;
 textcolor(YELLOW);
 clrscr();
 printf("Enter the Serial No:");
 scanf("%d",&n);
 fp=fopen("info.dat","r");
 found=0;
 while(fread(&cont,sizeof(cont),1,fp)!=NULL)
 {
    if(cont.sno==n)
    {
     printf("\nCategory     : %s",cont.category);
     printf("\nName         : %s",cont.name);
     printf("\nGender       : %c",cont.gender);
     printf("\nAge          : %d",cont.age);
     printf("\nAddress      : %s",cont.address);
     printf("\nPhone No     : %s",cont.phone);
     found=1;
     break;
    }
 }
 if(found==0)
 {
  printf("\nNot Found,Press any key....");
  fclose(fp);
  getch();
  return;
 }
 fclose(fp);
 getch();
}
//Search by Phone no
void search_phone()
{
 int n,found;
 char ph[15];
 FILE *fp;
 textcolor(YELLOW);
 clrscr();
 printf("Enter the Phone No:");
 gets(ph);
 fp=fopen("info.dat","r");
 found=0;
 while(fread(&cont,sizeof(cont),1,fp)!=NULL)
 {
    if(strcmp(ph,cont.phone)==0)
    {
     printf("\nCategory     : %s",cont.category);
     printf("\nName         : %s",cont.name);
     printf("\nGender       : %c",cont.gender);
     printf("\nAge          : %d",cont.age);
     printf("\nAddress      : %s",cont.address);
     printf("\nPhone No     : %s",cont.phone);
     found=1;
     break;
    }
 }
 if(found==0)
 {
  printf("\nNot Found,Press any key....");
  fclose(fp);
  getch();
  return;
 }
 fclose(fp);
 getch();
}
//Search by Category
 void search_category()
 {
  int i;
  char cat[20];
  FILE *fp;
  window(1,1,80,25);
  textbackground(WHITE);
  textcolor(BLUE);
  clrscr();
  printf("Enter Category:");
  gets(cat);
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
	 if(strcmpi(cat,cont.category)==0)
	 {
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
     }
     fclose(fp);
     textcolor(RED+BLINK);
     printf("\n");
     cprintf("Press any Key....");
  getch();
 }
 //Search by name
 void search_name()
 {
  int i;
  char na[20];
  FILE *fp;
  window(1,1,80,25);
  textbackground(WHITE);
  textcolor(BLUE);
  clrscr();
  printf("Enter name:");
  gets(na);
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
	 if(strcmpi(na,cont.name)==0)
	 {
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
     }
     fclose(fp);
     textcolor(RED+BLINK);
     printf("\n");
     cprintf("Press any Key....");
  getch();
 }