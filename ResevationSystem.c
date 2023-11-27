#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char ch[10][130]={"SimbaCoach-01","SimbaCoach-02","SimbaCoach-03","SimbaCoach-04","SimbaCoach-05","SimbaCoach-06","SimbaCoach-07","SimbaCoach-08"};
char name[32][100]={'\0'};
char number[32][2]={'\0'};
int num1[56]={0};
int busno;
void bus();//for list of bus
void name_number(int booking,char numstr[100]);
void booking();//for booking the tickets
int read_number(int busno);//for reading the number from the file
void read_name(int busno);//for reading the name from the file
void status();//for printing the status by user input
void status_1(int busno);//for printing the status while booking ticket
void cancel();

int main()
{
    system("color f1"); //color f0

	login();
    int num,i;
    do{
    system("cls");
    printf("\n\n\n");
    printf("\tSimba Bus Reservation System  \n");
    printf("\t____________________________\n\n");
    printf("\t1. Bus Available\n");
    printf("\n");
    printf("\t2. Book Ticket\n");
    printf("\n");
    printf("\t3. Cancel Booking\n");
    printf("\n");
    printf("\t4. Bus Status\n");
    printf("\n");
    printf("\t5. Exit\n\n");          
    printf("\t_____________________________\n\n");
    printf("\tEnter your choice: ");
    scanf("%d",&num);
    switch(num)
    {
    case 1:
         system("color f0");
        bus();
        printf("\n\n\t\tPress any key to exit this page.");
        break;
    case 2:
         system("color f8");
        booking();//for booking the tickets
        break;
    case 3:
        system("cls");
         system("color f4");
        cancel();
        break;
    case 4:
        system("cls");
         system("color f5");
        status();
        break;
    case 5:
         system("cls");
         system("color f1");
         printf("\t_________________________________________________\n");
         printf("\tThank you for using Simba Bus System.\t\t\t\t\t\t\n");
         printf("\t_________________________________________________\n");
         _getch();
         return 0;
    }
_getch();
    }while(num != 6);
    system("CLS");
    printf("\tInvalid choice!\n");
    printf("\t_______________________________________________\n");
    printf("\tThank you for using Simba Bus System.\t\t\t\t\t\n");
    printf("\t_______________________________________________\n");
    _getch();
    return 0;
}


void bus()
{   
	int price = 1300;
    system("cls");
    printf("\n\n\n");
    printf("_________________________________________ Simba Bus Company _________________________________________\n\n\n");
    printf("   S.NO.   |   BUS NO.     |    SOURCE  |    DESTINATION  |        DAYS     |       TIME        |   PRICE");
    printf("\n           |               |            |                 |                 |                   |         ");
    printf("\n    1.     | %-12s |  NAIROBI   |     KAKAMEGA    |  EVERYDAY       |  7am,2pm,8pm      |   %d    ", ch[0],price);
    printf("\n           |               |            |                 |                 |                   |          ");
    printf("\n    2.     | %-12s |  NAIROBI   |     KISUMU      |  EVERYDAY       |  7am,2pm,4pm,7pm  |   %d    ", ch[1],price);
    printf("\n           |               |            |                 |                 |                   |          ");
    printf("\n    3.     | %-12s |  NAIROBI   |     KERICHO     |  EVERYDAY       |  7am,2pm,5pm,8pm  |   %d    ", ch[2],price);
    printf("\n           |               |            |                 |                 |                   |          ");
    printf("\n    4.     | %-12s |  NAIROBI   |     MOMBASA     |  EVERYDAY       |  7am,2pm,8pm      |   %d    ", ch[3],price);
    printf("\n           |               |            |                 |                 |                   |          ");
    printf("\n    5.     | %-12s |  NAIROBI   |     TAITA       |  EVERYDAY       |  7am,2pm,4pm,7pm  |   %d    ", ch[4],price);
    printf("\n           |               |            |                 |                 |                   |          ");
    printf("\n    6.     | %-12s |  NAIROBI   |     KISII       |  EVERYDAY       |  7am,2pm,4pm,7pm  |   %d    ", ch[5],price);
    
}



void booking()
{
    
    int i=0;
    char numstr[100];
system("cls");
printf("=========================================== Simba Bus Company ============================================\n\n\n");//for entering bus number
bus();
printf("\n\nEnter Bus Number(1-6): ");
scanf("%d",&busno);
system("cls");
printf("=========================================== Simba Bus Company ============================================\n\n\n");//for selecting seat
printf("\n\nYour Bus Number is %d \t %s",busno,ch[busno-1]);
status_1(busno);
 FILE *f1, *fopen();//for reading the seats from the user.
 char sbs1[80]="56",sbs2[4],sbs3[4];
 int seat1,seat2,booking=0;

 
if(busno == 1)
{
 f1 = fopen("bs1.txt","r+");//r+ searches file and read from 1st character
 fgets(sbs1,80,f1);
 fclose(f1);
}else if(busno == 2)
{
 f1 = fopen("bs2.txt","r+");
 fgets(sbs1,80,f1);
 fclose(f1);
}else if(busno == 3)
{
 f1 = fopen("bs3.txt","r+");
 fgets(sbs1,80,f1);
 fclose(f1);
}
else if(busno == 4)
{
 f1 = fopen("bs4.txt","r+");
 fgets(sbs1,80,f1);
 fclose(f1);
}
else if(busno == 5)
{
 f1 = fopen("bs5.txt","r+");
 fgets(sbs1,80,f1);
 fclose(f1);
}
seat1=atoi(sbs1);//covert the string into number
if(seat1 <= 0)
{
 printf("\n\nAll seats are occupied");
}else
{
printf("\n\n\n\t\t\t\tAvailable seats are: %d\n",seat1);
printf("\n\t\t\t\tHow many seats are you booking?: ");
scanf("%d",&booking);//no of tickets input
printf("\n");

seat1=seat1-booking;
itoa(busno,numstr,10);
name_number(booking,numstr);
printf("\n\t\t\t**-------- Receipt ---------**\n");
printf("\n\t\t\tThe total amount is %d",1300*booking);
printf("\n\n\t\t\tYour Bus Number is %d \t %s",busno,ch[busno-1]);
printf("\n\t\t\t**--------------------------**\n");
printf("\n\t\t\tPress any key to continue...");
itoa(seat1, sbs1, 10);//for reading the seats from the user.
if(busno == 1)
{
 f1 = fopen("bs1.txt","w");//write the name and no. of passenger in file
 fputs(sbs1,f1);
 fclose(f1);
}
else if(busno == 2)
{
 f1 = fopen("bs2.txt","w");
 fputs(sbs1,f1);
  fclose(f1);
}
else if(busno == 3)
{
 f1 = fopen("bs3.txt","w");
 fputs(sbs1,f1);
  fclose(f1);
}
else if(busno == 4)
{
 f1 = fopen("bs4.txt","w");
 fputs(sbs1,f1);
  fclose(f1);
}
else if(busno == 5)
{
 f1 = fopen("bs5.txt","w");
 fputs(sbs1,f1);
 fclose(f1);
}
}
}



void name_number(int booking,char numstr[100])
{
char tempstr[100],tempsbs1[12]="status",tempsbs2[12]="number";
int number;
    FILE *a,*b;
    int i=0;
   strcat(numstr,".txt");
   strcat(tempsbs1,numstr);
   strcat(tempsbs2,numstr);
   a = fopen(tempsbs1,"a");//for open the file to write the name in the file
   b = fopen(tempsbs2,"a");//for open the file for writing the number in the file
for(i=0; i<booking; i++)//for entering the person name and seat number in the file
{
    printf("============================Enter details for %d Ticket ============================\n\n\n",i+1);
      printf("\t\t\t\tEnter Seat Number: ");
      scanf("%d",&number);
      printf("\t\t\t\tEnter Passenger's Name: ");
      scanf("%s",name[number-1]);
    printf("\n======================================================================================================\n\n");
    printf("\n");
      itoa(number, tempstr, 10);
      fprintf(a,"%s ",name[number-1]);
      fprintf(b,"%s ",tempstr);

}
fclose(a);
fclose(b);
}



int read_number(int busno)//for putting the numeric value in the array
{
char tempstr[100],tempsbs2[12]="number";
FILE *a,*b;
char numstr[100];
int i=0,j=0,k;
itoa(busno,numstr,10);
strcat(numstr,".txt");
strcat(tempsbs2,numstr);
a = fopen(tempsbs2,"a+");//for open the file to read the name in the file
   while(!feof(a))//file end of file
   {
      number[i][j] = fgetc(a);//gets the character from file pointer a

      if(number[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
      j++;
      }
   }
   k=i;
   for(i=0; i<k; i++)
   {
       num1[i] = atoi(number[i]);//atoi string to integer
   }
   fclose(a);
   return k;
}


void read_name(int busno)//for putting the numeric value in the array
{
char tempsbs1[12]="status";
FILE *b;
char numstr[100];
int i=0,j=0,k=0;
itoa(busno,numstr,10);
strcat(numstr,".txt");
strcat(tempsbs1,numstr);
b = fopen(tempsbs1,"a+");//for open the file to write the name in the file
   while(!feof(b))
   {
      name[i][j] = fgetc(b);

      if(name[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
        j++;
      }

   }
   name[i][j]='\0';
   k=i;
   fclose(b);
}
void status()
{
system("cls");//seat matrix
printf("=========================================== Simba Bus Company ============================================\n\n\n");
    int i,busno,index=0,j;
    printf("Enter Bus Number: ");
    scanf("%d",&busno);
    j=read_number(busno);
    read_name(busno);
    printf("____________________________________________________________________________________________________________________\n");
    printf("                                     Bus No. %d \t %s                                                            \n",busno,ch[busno-1]);
    printf("____________________________________________________________________________________________________________________\n");
    char tempname[57][10]={"Empty ","Empty","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);
    }
    for(i=0; i<14; i++)
    {
        printf("\t\t\t\t");
        for(j=0; j<4; j++)
            {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
            }
            printf("\n");
    }
}

void status_1(int busno)
{
    printf("Your Bus Number is %d \t %s",busno,ch[busno-1]);
    system("cls");
printf("=========================================== Simba Bus Company ============================================\n\n\n");
    int i,index=0,j;
    j=read_number(busno);//read and save seat no
    read_name(busno);//read and save name of person
    char tempname[57][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);
    }
    for(i=0; i<14; i++)
    {
        printf("\t\t\t\t");
        for(j=0; j<4; j++)
            {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
            }
            printf("\n");
}
}

void cancel()
{
 int seat_no,i,j;
 char numstr[100],tempsbs2[15]="number",tempsbs1[15]="status";
 printf("_____________________________________________________________________________________________________________\n");
 printf("\n\nCancellation Fee = ksh 100 per Ticket\n");
 printf("_____________________________________________________________________________________________________________\n");
 printf("\n");
 printf("\n\nEnter Bus Number: ");
 scanf("%d",&busno);
 itoa(busno,numstr,10);
 strcat(numstr,".txt");
 strcat(tempsbs1,numstr);
 strcat(tempsbs2,numstr);
 read_number(busno);
 read_name(busno);
 status_1(busno);
 printf("\nEnter Seat Number: ");
 scanf("%d",&seat_no);
 FILE *a,*b;
 a = fopen(tempsbs1,"w+");
 b = fopen(tempsbs2,"w+");
 for(i=0; i<57; i++)
 {
     if(num1[i] == seat_no)
     {
         for(j=0; j<57; j++)
         {
             if(num1[j] != seat_no && num1[j] != 0)
             {
                 fprintf(b,"%d ",num1[j]);
                 fprintf(a,"%s",name[j]);
             }
             else if(num1[j] == seat_no && num1[j] != 0)
             {
                 strcpy(name[j],"Empty ");
             }
         }
     }
 }
fclose(a);
fclose(b);
printf("\n\n");
 printf("======================================================================================================\n");
 printf("\t\t\t\tYour Booking has been cancelled successfully.\t\t\t\n");
    printf("======================================================================================================\n");
 printf("\t\t\t\tKindly wait as we process the refunding of your money.\t\t\t\n");
    printf("======================================================================================================\n");
    printf("\n\t\t\t\tPress any key to continue...");
}

void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{
	system("cls");
	printf("\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t______________________________________________________\n");
    printf("\n\t\t\t\t\t\t\t\t  SIMBA BUS COMPANY\n");
    printf("\t\t\t\t\t\t______________________________________________________\n\n");
    printf("\t\t\t\t\t\t  Simba Bus Company is committed to providing\n");
    printf("\t\t\t\t\t\t  safe and reliable transportation services.\n");
    printf("\n\t\t\t\t\t\t  Please login to access the system.    \n");
    printf("\t\t\t\t\t\t______________________________________________________\n");
    printf(" \n\t\t\t\t\t\t  Enter Your name: ");
	scanf("%s", &uname);
	printf(" \n\t\t\t\t\t\t  Enter Password: ");
    while (i < 10) {
    pword[i] = _getch();
      c = pword[i];
     if (c == 13) {
        break;
     } else if (c == 8) {
        if (i > 0) {
            printf("\b \b");
            i--;
        }
    } else {
        printf("*");
        i++;
    }
}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword);
		if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
    printf("\n\t\t\t\t\t\t______________________________________________________\n\n");
	printf("\n\n\n\t\t\t\t\t\t  Welcome to Simba Bus Company \n\n\t\t\t\t\t\t  We value your patronage and are delighted to serve you!\n");
	printf("\n\t\t\t\t\t\t______________________________________________________\n");
	printf("\n\t\t\t\t\t\t\tPress any key to continue...");
	
	_getch();//holds the screen
	break;
	}
	else
	{
		printf("\n\t\t\t\t\t\tInvalid username or password!  ");
		a++;

		_getch();//holds the screen

	}
}
	while(a<=4);
	if (a>4)
	{
		printf("\t\t\t\t\t\tInvalid username or password!");

		_getch();

		}
		system("color f0");
		system("cls");
}


