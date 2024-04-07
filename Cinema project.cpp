#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define NAME 50
#define MOVIE 100
#define ID 30
#define MASA 45
#define SPACE 15
#define SERIES 75

FILE * fmovie;
FILE * fmoney;
FILE * fpopcorn;
FILE * fname;
FILE * fpin;
FILE * ftotal;

char jam[5][MASA] ={"10.30-12.30","12.30-14.30","15.00-17.00","17.00-19.00","20.30-22.30"};
char movie[5][MOVIE];
char nourishment[3][SERIES]={"Popcorn","Nachos","Sausage"};
char beverage[3][SERIES]={"Pepsi","Coca cola","Lemon tea"};
char name[20][NAME];
char tag[20][NAME];
char row[2];
int u,v,w,j;

void animation(int q);
void load_movie(float price[]);
void front_page();
void customer();
void intro();
void loadUsername(int code[]);
void availability(int length[], int number[]);
int  regMembership(int position, int count5, int member, int count1, int code[], int recode, int okay);
void time();
void listMovie(float price[],float numMovie,int space);
int screen(int seat);
float save_beverage(int menu,int food[], int drink[], int totalFood[], int totalDrink[], int redo, float cost[], float beverageCost);
void staff();
void lastweek_profit(float profit);
float lastWeek_movie(float price[]);
void save_movie(float price[], int confirm);
float confirm_movie(float price[]);
void load_beverage(int totalFood[], int totalDrink[]);
int refill_beverage(int chooseRefill, int i, int refill, int totalFood[], int totalDrink[], int food[], int drink[]);

int main()
{ 
	int food[3]={0,0,0},drink[3]={0,0,0},totalFood[3]={100,100,100},totalDrink[3]={100,100,100},refill;
	int membership,confirm, pin,member=0,member1,code[20],recode,reset;
	int password;
	int okay,regMem;
	int menu,redo;
	int i,n,q;
	int count1= 0, count2=0, count3=0, count4=0, count5=0;
	int day,month;
	int space;
	int number[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	int position;
	int length[20];
	int room[5]={1,2,3,4,5};
	int chooseRefill;
	int seat,seating;
	char choose;
	char id[ID];
	char copy[MOVIE];
	char username[NAME];
	char nickname[NAME];
	float numMovie,price[5],loop;
	float cost[6]={0,0,0,0,0,0};
	float totalPrice;
	float beverageCost;
	float profit;
	
    load_movie(price);
    
    animation(q);
	do
	{
	front_page();
	system("cls");
	printf("----------------------WELCOME-----------------------------\n\n");
	printf("Are you a customer or staff? ( c for customer and s for staff) : ");
	("%c",&choose);
	if(choose=='c'||choose=='C')
	{
		
		customer();
		printf("What should we call you? :");
	    scanf("%s",&nickname);
	    printf("\nPress any key to continue");
	    getch();
		intro();
        
		printf("\nDo you want to register for membership? < Press 1 to register > :");
	    scanf("%d",&regMem);
	    
	    
		if(regMem==1) 
		{ 
		    loadUsername(code);
			system("cls");
            availability(length, number);
		    member1 =regMembership(position,count5,member,count1,code,recode,okay);
		}
		
	    else
	    	//nothing, just proceed
		
        system("cls");		  
        loadUsername(code);	

	do
    {  		
		printf("Do you have membership ? (1 for yes and 2 for no) : ");
        scanf("%d",&membership);

    if(membership==1)
	{   
        availability(length, number);
	        
	        printf("Enter your list :");
	        scanf("%d",&position);
	        j =position-1;
      
		do
		{
			do
			{
		       do
		        {    
				    system("cls");
				    if(count2!=0)
					printf("\nYour username or password is invalid\n");    	
    				printf("Enter your username :");
    				scanf("%s",&username);
    				printf("\nEnter your pin(6 digit) :");
    				scanf("%d",&pin);
    				system("cls");
   				 	printf("Your name is '%s'\n",username);
    				printf("Your pin  is '%d'\n",pin);
    				printf("\n\nconfirming this is your username and pin?(press 0 to confirm) : ");
    				scanf("%d",&confirm);
    				count2++;
    				if(count2==3)
    				goto starter;
    		   }while(confirm!=0);
    		}while(pin!=code[j]);
		}while(strcmp(username,name[j])!=0);     
	   
	count2=0;   
    system("cls");

	        
	    for(i=0;i<5;i++)
	       price[i]-=price[i]*0.1;
	       

	    time();    
		listMovie(price,numMovie,space);
	}

    else if(membership==2)
	{  
	    starter:
	    if(count2==3)
	    {
		printf("\nYou have try for 3 times already!!\n");	
		printf("Press any key to continue");
		getch();
	    }
		system("cls");
		
        time();
	    listMovie(price,numMovie,space);					
	}
	  
	if(membership!=1 && membership !=2)
    printf("\nInvalid number\n"); 
    }while(membership!=1 && membership!=2);
	
	system("cls");
     
    time_t sekarang;
	time(&sekarang);
	struct tm *myTime= localtime(&sekarang);
	printf("\n\nToday date is %i/%i/%i\n",myTime->tm_mday,myTime->tm_mon+1,myTime->tm_year+1900);
	
	do
	{
		do
		{
			do
			{
		        if(count4!=0)
		        printf("\nInvalid date or month");
	            printf("\nEnter your date for booking (day/month) :");
	            scanf("%d %d",&day,&month);
	            count4++;
	        }while(day<myTime->tm_mday && month<myTime->tm_mon+1);
        }while(day>31);
   }while(month>12 || month<myTime->tm_mon+1); 
	count4=0; 
	
	seating = screen(seat);
	
	fpopcorn=fopen("beverage.txt","r");
	fscanf(fpopcorn,"%d %d %d %d %d %d",&totalFood[0],&totalFood[1],&totalFood[2],&totalDrink[0],&totalDrink[1],&totalDrink[2]);	
	fclose(fpopcorn);       
	
	beverageCost = save_beverage(menu,food,drink,totalFood,totalDrink,redo,cost,beverageCost); 
	totalPrice =beverageCost+price[u]+member1;   
	
	system("cls");
	system("COLOR 0C");
	printf("\n");
	printf(" ***** * * * * * * * * * * * * * * * * * * * * * * * * * * * * *****\n");
	printf(" ****  * * * * * * * * * * * * * * * * * * * * * * * * * * * *  ****\n");
	printf(" ***                                                                 \n");	 
	printf(" **                       GEMPAK CINEMA                             \n");	
	printf(" **           Thank you for your purchase %s         \n",nickname);
	printf(" **                                                   \n");
	printf(" **   Film tittle : %s                         \n",movie[u]);
	printf(" **   Time : %s                                    \n",jam[w]);
	printf(" **   Room : %d                                      \n",room[v]);
	printf(" **   Date : %d/%d/2021                             \n",day,month);
    printf(" **   Seat : %s%d                                    \n",row,seating);
	printf(" **                                                     \n");
	printf(" **   Movie price : RM%.2f                          \n",price[u]);
	printf(" **   Beverage price : RM%.2f                        \n",beverageCost);
	printf(" **                                                     \n");
	printf(" **                                                     \n");
	printf(" **   Total price : RM%.2f                                        \n",totalPrice);
	printf(" **                                                                 \n");
	printf(" ***                                                                \n");
	printf(" ****  * * * * * * * * * * * * * * * * * * * * * * * * * * * *  ****\n");    
	printf(" ***** * * * * * * * * * * * * * * * * * * * * * * * * * * * * *****\n");
	
        	ftotal=fopen("profit.txt","r");
	        fscanf(ftotal,"%f",&profit);	
	        fclose(ftotal);
	        
	        profit +=totalPrice;
	        
		    ftotal=fopen("profit.txt","w");	
	        fprintf(ftotal,"%f",profit);	
	        fclose(ftotal);  
	        
	        
	printf("\n\nPress 0 to back to main page :");
	scanf("%f",&loop);		
}

else if(choose=='s'||choose=='S')
{
	staff();
    here:
    if(count3 ==3)
    {
    	loop =0;  
    	count3=0;
	    printf("\nYou have tried for 3 times!!");
        printf("\nPress any key to continue");
        getch();
        system("cls");
    }
	else
    {
	do
	{
		do
		{
			system("cls");
			if(count3 !=0)
				printf("Your id or password is invalid\nPlease reenter\n\n");		
			printf("Enter your id :"); //Razman
			scanf("%s",&id); //123456
			printf("Enter your password :");
			scanf("%d",&password);
			count3++;
			if(count3==3)
			goto here;
    	}while(strcmp(id,"Razman")!=0);
	}while(password!=123456);
	count3=0;

	printf("\nPress any key to continue");
	getch();
	system("cls");
	
	lastweek_profit(profit);        
	
    lastWeek_movie(price);
    
    save_movie(price,confirm);
	  
	load_beverage(totalFood, totalDrink);

	refill_beverage(chooseRefill,i,refill,totalFood,totalDrink,food,drink);
	
	system("cls");
	time_t sekarang;
	time(&sekarang);
	struct tm *myTime= localtime(&sekarang);
	printf("\n\nToday date is %i/%i/%i\n",myTime->tm_mday,myTime->tm_mon+1,myTime->tm_year+1900);
	
	printf("Reset all the membership subscription ? < Press 1 for yes >");
	scanf("%d",&reset);
	if(reset==1)
	{
		for(u=0;u<20;u++)
		{
		   strcpy(name[u],"");
		   code[u]=0;
     	}
    }
   			fname=fopen("names.txt","w");
	        fprintf(fname,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",name[0],name[1],name[2],name[3],name[4],name[5],name[6],name[7],name[8],name[9],name[10],name[11],name[12],name[13],name[14],name[15],name[16],name[17],name[18],name[19]);	
	        fclose(fname);
	        
	        fpin=fopen("password.txt","w");	       
	        fprintf(fpin,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",code[0],code[1],code[2],code[3],code[4],code[5],code[6],code[7],code[8],code[9],code[10],code[11],code[12],code[13],code[14],code[15],code[16],code[17],code[18],code[19]);	
	        fclose(fpin);  
   
printf("\n\nPress 0 to back to main page :");
scanf("%f",&loop);
}
}

}while(loop==0);

printf("\nThank you");
	return 0;
}

void load_movie(float price[])
{
	fmovie=fopen("movie.txt","r");
	fscanf(fmovie,"%s %s %s %s %s",&movie[0],&movie[1],&movie[2],&movie[3],&movie[4]);
	fclose(fmovie);
		     
	fmoney=fopen("money.txt","r");
	fscanf(fmoney,"%f %f %f %f %f",&price[0],&price[1],&price[2],&price[3],&price[4]);	
	fclose(fmoney);
}

void front_page()
{
	system("cls");
	system("COLOR 0E");
    printf("\t\t\t\t\t======================================================");
	printf("\n\n\t\t\t\t\t\t\tWELCOME TO GEMPAK CINEMA");
	printf("\n\n\t\t\t\t\t======================================================");

	
	
	printf("\n\n\t\t\t\t\t\t       Become a member today and get \n\t\t\t\t\t             10 percents off for your movies!!");

	printf(" \n\n\n\n\t\t\t\t  =================");	
	printf("\t =================");
	printf("\t =================");

	
	printf("\n\t\t\t\t  ||             ||\t");
	printf(" ||             ||\t");
	printf(" ||             ||\t\n");

	
	printf("\t\t\t\t  ||   MOVIE 1   ||\t");
	printf(" ||   MOVIE 2   ||\t");
	printf(" ||   MOVIE 3   ||\t");

	
	printf("\n\t\t\t\t  ||             ||\t");
	printf(" ||             ||\t");
	printf(" ||             ||\t\n");

	
	printf("\t\t\t\t  ||  BOOK YOUR  ||\t");
	printf(" ||  BOOK YOUR  ||\t");
	printf(" ||  BOOK YOUR  ||\t");	

	
	printf(" \n\t\t\t\t  || SEAT NOW!!  ||\t");
	printf(" || SEAT NOW!!  ||\t");
	printf(" || SEAT NOW!!  ||\t");		
		
	
	printf("\n\t\t\t\t  ||             ||\t");
	printf(" ||             ||\t");
	printf(" ||             ||\t\n");	
	
	
	printf("\t\t\t\t  =================");	
	printf("\t =================");
	printf("\t =================");	
	
	
	printf(" \n\t\t\t\t\t  =================");
	printf("\t\t =================");
	
	printf("\n\t\t\t\t\t  ||             ||\t\t");
	printf(" ||             ||\t");
	
	printf("\n\t\t\t\t\t  ||   MOVIE 4   ||\t\t");
	printf(" ||   MOVIE 5   ||\t");	
	
	printf("\n\t\t\t\t\t  ||             ||\t\t");
	printf(" ||             ||\t");
	
	printf("\n\t\t\t\t\t  ||  BOOK YOUR  ||\t\t");
	printf(" ||  BOOK YOUR  ||\t");
	
	printf(" \n\t\t\t\t\t  || SEAT NOW!!  ||\t\t");
	printf(" || SEAT NOW!!  ||\t");	
	
	printf("\n\t\t\t\t\t  ||             ||\t\t");
	printf(" ||             ||\t");	
	
	printf("\n\t\t\t\t\t  =================");	
	printf("\t\t =================");	
	
	
	printf("\n\n\n\n\t\t\t\t\t ************ PRESS ANY KEY TO CONTINUE ************");
	getch();
}

void customer()
{
	system("COLOR 0B");
		
	printf("\n\n      CUSTOMER                                               \n");
	printf("                                              \n");
	printf("     \\              /                     \n");
	printf("  \\            /                             \n");
	printf("        _____                                      \n");
	printf("       | > < |  ___              \n");
	printf("       | www | {_$_}               \n");
	printf("    \\  |_____|   /                 \n");
	printf("     \\    |     /              \n");
	printf("      \\===|====/                   \n");
	printf("          |                       \n");
	printf("          |                       \n");
	printf("          |                          \n");
	printf("          |                            \n");
	printf("         / \\                         \n");
	printf("        /   \\                          \n");
	printf("       /     \\                        \n");
	printf("      /       \\                              \n");
	printf("\n\nPress any key to continue");
	getch();
	system("cls");
}

void intro()
{	
	system("cls");
	printf(" \n----------- Benefit of membership ----------          \n");
	printf(" =============================================        ____              \n");	
	printf(" ||                                         ||       / * /          \n");
	printf(" || Membership will get 10 percent discount ||      / * /     \n");
	printf(" || Fee = RM10.00/month                     ||     /_*_/______    \n");
	printf(" || Limited to 20 member per month          ||     |* * * * *|          \n");
	printf(" ||                                         ||     | PREMIUM |        \n");
	printf(" =============================================     |_________|                  \n");
}

void loadUsername(int code[])
{
		fname=fopen("names.txt","r");
	    fscanf(fname,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",&name[0],&name[1],&name[2],&name[3],&name[4],&name[5],&name[6],&name[7],&name[8],&name[9],&name[10],&name[11],&name[12],&name[13],&name[14],&name[15],&name[16],&name[17],&name[18],&name[19]);	
	    fclose(fname);
		
		fpin=fopen("password.txt","r");
	    fscanf(fpin,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",&code[0],&code[1],&code[2],&code[3],&code[4],&code[5],&code[6],&code[7],&code[8],&code[9],&code[10],&code[11],&code[12],&code[13],&code[14],&code[15],&code[16],&code[17],&code[18],&code[19]);	
	    fclose(fpin);
}

void availability(int length[], int number[])
{
		for(u=0;u<20;u++)
        {
    	        length[u] = strlen(name[u]);
                if(length[u]!=0)
                strcpy(tag[u],"already booked");
                else 
                strcpy(tag[u],"avalaible");
	    }
		 
		printf(" List of membership : \n");
	  	printf(" _____________________________________\n");
        printf(" ");
		for(u=0;u<9;u++)
	    printf("\n  %d  : %s",number[u],tag[u]);
		for(u=9;u<20;u++)
	    printf("\n  %d : %s",number[u],tag[u]);	
	    printf("\n _____________________________________\n");
}

int regMembership(int position, int count5, int member, int count1, int code[], int recode, int okay )
{
		do
		{
			printf("\n\nPlease enter your chosen position :");
		    scanf("%d",&position);
	        j =position-1;
            if(strcmp(tag[j],"already booked")==0)
            {
              printf("Access denied");
              count5++;
	        } 
	        else if(strcmp(tag[j],"available")!=0)
	        {
	           count5=0;	
	        }
	        
        }while(count5!=0);
               system("cls");
               
        do
		{		
		    member =10;
			do
			{
			  if(count1 !=0)
			  {
				system("cls");
		        printf("Password do not match\n");
		      }		       
		       
	           printf("\nPlease register your name :");
	           scanf("%s",&name[j]);	
	           printf("\nPlease register your password :");
	           scanf("%d",&code[j]);
	           printf("\nPlease re-enter your password :");
	           scanf("%d",&recode);
	           printf("\nDo you want to confirm your registration? ( Press 0 to confirm) :");
	           scanf("%d",&okay);
			   count1++; 
			   if(count1==3)
	               goto start;			   
	        }while(code[j]!=recode);      
	    }while(okay!=0);
	   
	           fprintf(fname,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",name[0],name[1],name[2],name[3],name[4],name[5],name[6],name[7],name[8],name[9],name[10],name[11],name[12],name[13],name[14],name[15],name[16],name[17],name[18],name[19]);	
	           fclose(fname);
	           fname=fopen("names.txt","w");
	   
	           fpin=fopen("password.txt","w");
	           fprintf(fpin,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",code[0],code[1],code[2],code[3],code[4],code[5],code[6],code[7],code[8],code[9],code[10],code[11],code[12],code[13],code[14],code[15],code[16],code[17],code[18],code[19]);	
	           fclose(fpin);
	           
			   
			   	                    		         	           
    start:
	if(count1==3)
	{
		printf("You have try for 3 times already!!\n");
		member=0; 
		printf("Press any key to continue");
		getch();
	}
		return member;
}

void time()
{
	time_t sekarang;
	time(&sekarang);
	struct tm *myTime= localtime(&sekarang);
	
	if(myTime->tm_min<10)
    printf("\n\nTime now is %i:0%i",myTime->tm_hour,myTime->tm_min);
    else
	printf(" Time now is %i:%i\n\n",myTime->tm_hour,myTime->tm_min);
}

void listMovie(float price[],float numMovie,int space)
{
	printf("  List of movies \n\n");    
	printf("  _____________________________________________________________________________________________       \n"); 
	printf(" |        |                |                |                |                |                |      \n");
	printf(" |  Room  |     Room 1     |     Room 2     |     Room 3     |     Room 4     |     Room 5     |     \n");
	printf(" |________|________________|________________|________________|________________|________________|        \n");
    printf(" |        |                |                |                |                |                |      \n");
    printf(" |        |                |                |                |                |                |      \n");
	printf(" |   T    |  %s   |  %s   |  %s   |  %s   |  %s   |   =   %s\n",jam[0],jam[1],jam[2],jam[3],jam[4],movie[0]); 
	printf(" |        |                |                |                |                |                |      \n");
	printf(" |        |________________|________________|________________|________________|________________|        \n"); 
    printf(" |        |                |                |                |                |                |      \n");
    printf(" |        |                |                |                |                |                |      \n");
	printf(" |   I    |  %s   |  %s   |  %s   |  %s   |  %s   |   =   %s\n",jam[1],jam[2],jam[3],jam[4],jam[0],movie[1]); 
	printf(" |        |                |                |                |                |                |      \n");
	printf(" |        |________________|________________|________________|________________|________________|        \n");
    printf(" |        |                |                |                |                |                |      \n");
    printf(" |        |                |                |                |                |                |      \n");
	printf(" |   M    |  %s   |  %s   |  %s   |  %s   |  %s   |   =   %s\n",jam[2],jam[3],jam[4],jam[0],jam[1],movie[2]); 
	printf(" |        |                |                |                |                |                |      \n");
	printf(" |        |________________|________________|________________|________________|________________|        \n");
    printf(" |        |                |                |                |                |                |      \n");
    printf(" |        |                |                |                |                |                |      \n");
	printf(" |   E    |  %s   |  %s   |  %s   |  %s   |  %s   |   =   %s\n",jam[3],jam[4],jam[0],jam[1],jam[2],movie[3]); 
	printf(" |        |                |                |                |                |                |      \n");
	printf(" |        |________________|________________|________________|________________|________________|        \n");
    printf(" |        |                |                |                |                |                |      \n");
    printf(" |        |                |                |                |                |                |      \n");
	printf(" |   S    |  %s   |  %s   |  %s   |  %s   |  %s   |   =   %s\n",jam[4],jam[0],jam[1],jam[2],jam[3],movie[4]); 
	printf(" |        |                |                |                |                |                |      \n");
	printf(" |________|________________|________________|________________|________________|________________|        \n");    
	
	printf("\n\n Code for movies:\n\n");
	printf(" 1) %s = RM%.2f       \n",movie[0],price[0]);
	printf(" 2) %s = RM%.2f       \n",movie[1],price[1]);
	printf(" 3) %s = RM%.2f      \n",movie[2],price[2]);
    printf(" 4) %s = RM%.2f      \n",movie[3],price[3]);
	printf(" 5) %s = RM%.2f      \n\n",movie[4],price[4]);
	
	 		printf("\n\n Choose your code for movie? <1,2,3,4,5>:");
	        scanf("%f",&numMovie);
	    
	        u =numMovie-1;
		  
	        printf(" Choose your room :");
	        scanf("%d",&space);
			       
    if(numMovie==1)
    {
    	v =space-1;
    	w =space-1;
	}
	
	else if(numMovie==2)
    {
    	v =space-1;
    	if(space==5);
    	w =space-5;
    	if(space!=5)
    	w =space;
	}
	
	else if(numMovie==3)
    {
    	v =space-1;
    	if(space==5 || space==4)
    	w =space-4;
    	if(space!=5 && space!=4)
    	w =space+1;
	}
	
	else if(numMovie==4)
    {
    	v =space-1;
    	if(space==1 || space==2)
    	w =space+2;
    	if(space!=1 && space!=2)
    	w =space-3;  	
	}
	
	else if(numMovie==5)
    {
    	v =space-1;
    	if(space==1)
    	w =space+3;
    	if(space!=1)
    	w =space-2;
    }
    
}

int screen(int seat)
{
			printf("\nPress any key to continue");
            getch();
            system("cls");
     
	v++;        
	printf("                                 _________     \n");
	printf("                                |         |   \n");
    printf(" -------------------------------| Room %d  |--------------------------------------\n",v);
    printf("                                |_________|     \n\n");
	printf("               _______________________________________________\n");
	printf("          ____|                                               |______\n");
	printf(" ________|                        screen                             |__________\n");
	printf(" ||                                                                           ||\n\n");
	printf(" ||                                                                           ||\n\n");	
	printf(" ||  F1 F2    F3  F4  F5  F6  F7  F8  F9  F10  F11  F12  F13  F14    F15 F16  ||\n\n");
	printf(" ||  E1 E2    E3  E4  E5  E6  E7  E8  E9  E10  E11  E12  E13  E14    E15 E16  ||\n\n");
	printf(" ||  D1 D2    D3  D4  D5  D6  D7  D8  D9  D10  D11  D12  D13  D14    D15 D16  ||\n\n");
	printf(" ||  C1 C2    C3  C4  C5  C6  C7  C8  C9  C10  C11  C12  C13  C14    C15 C16  ||\n\n");
	printf(" ||  B1 B2    B3  B4  B5  B6  B7  B8  B9  B10  B11  B12  B13  B14    B15 B16  ||\n\n");
	printf(" ||  A1 A2    A3  A4  A5  A6  A7  A8  A9  A10  A11  A12  A13  A14    A15 A16  ||\n\n");
	printf(" ||___________________________________________________________________________||\n");
	
		printf(" \n\nPlease choose your row :");
	    scanf("%s",&row);
	    printf(" Please choose your seat :");
	    scanf("%d",&seat);
	    
	return seat;    
}

float save_beverage(int menu,int food[], int drink[], int totalFood[], int totalDrink[], int redo, float cost[],float beverageCost)
{
		system("cls");
	     printf("======List of food and beverage======");
	     printf("\n\n______________________________ ");
	     printf("\n||                           ||");
		 printf("\n||   1) %s   = RM8.50   ||              ",nourishment[0]);
	     printf("\n||   2) %s    = RM3.70   ||              ",nourishment[1]);
	     printf("\n||   3) %s   = RM3.00   ||          |   ",nourishment[2]);
	     printf("\n||   4) %s     = RM2.50   ||       ___|___",beverage[0]);
	     printf("\n||   5) %s = RM2.50   ||       |-  --|",beverage[1]);
	     printf("\n||   6) %s = RM2.00   ||       | --  |",beverage[2]);
	     printf("\n||                           ||       |     |");
	     printf("\n||   0) Do not order         ||       |-  --|");
	     printf("\n||___________________________||       |_____|");

    do
    {
	  printf("\n\nWhat is your menu? :");
	  scanf("%d",&menu);
	switch(menu)
	{
	
	case 1:
	    printf("\n\nHow many %s that you want to order? : ",nourishment[0]);  
	    scanf("%d",&food[0]);
	    totalFood[0] -=food[0];	    
        break;
    
    case 2:
	    printf("\n\nHow many %s that you want to order? : ",nourishment[1]);  
	    scanf("%d",&food[1]);
		totalFood[1] -=food[1];		
        break;
        
    case 3:
	    printf("\n\nHow many %s that you want to order? : ",nourishment[2]);  
	    scanf("%d",&food[2]); 
	    totalFood[2] -=food[2];	    
        break;
    
    case 4:
         printf("\n\nHow many %s that you want to order?   : ",beverage[0]);  
	     scanf("%d",&drink[0]);
	     totalDrink[0] -=drink[0];	     
         break;
         
    case 5:
         printf("\n\nHow many %s that you want to order?   : ",beverage[1]);  
	     scanf("%d",&drink[1]);
	      totalDrink[1] -=drink[1];
         break;
         
    case 6:
         printf("\n\nHow many %s that you want to order?   : ",beverage[2]);  
	     scanf("%d",&drink[2]);
	      totalDrink[2] -=drink[2];	      
         break;
    
	default:
	break;     
    }

    printf("\nPress 0 to order again :");
    scanf("%d",&redo);
       
	}while(redo==0);
	cost[0]+=(food[0]*8.50);
    cost[1]+=(food[1]*3.70);
    cost[2]+=(food[2]*3.00);
    cost[3]+=(drink[0]*2.50);
    cost[4]+=(drink[1]*2.50);
    cost[5]+=(drink[2]*2.00);
    
    fpopcorn=fopen("beverage.txt","w");
    fprintf(fpopcorn,"%d %d %d %d %d %d",totalFood[0],totalFood[1],totalFood[2],totalDrink[0],totalDrink[1],totalDrink[2]);	
	fclose(fpopcorn);
		
	return cost[0]+cost[1]+cost[2]+cost[3]+cost[4]+cost[5]-beverageCost;
}

void staff()
{
	system("COLOR 0A");	                          

    printf("\n\n                                    STAFF                                           ");
	printf("                                                 \n");
	printf("                                    _____\n");
	printf("                                   (_____)                                         \n");
	printf("                                   | . . |                         \n");
	printf("                                   | ___ |                            \n");
	printf("                                   |_____|                         \n");
	printf("                                      |                           \n");
	printf("                                    ,=|=,                          \n");
	printf("                                    | | |                                     \n");
	printf("                                    | | |                                     \n");
	printf("                                      |                                           \n");
	printf("                                      |                                            \n");
	printf("                                    ,===,                                  \n");
	printf("                                    |   |                                  \n");
	printf("                                    |   |       \n");
	printf("                                    |   |         \n");
    printf("\n\n                           Press any key to continue"); 
	getch();
	system("cls");
}

void lastweek_profit(float profit)
{
            ftotal=fopen("profit.txt","r");
	        fscanf(ftotal,"%f",&profit);	
	        fclose(ftotal);
	        
            printf(" *   *   *   *   *   *   *   *   *   *   *   *   *   * \n"); 	        
			printf("     _____________________________________________\n");         
	        printf(" *  |     \n");
	        printf("    | Total profit for this week is RM%.2f\n",profit);
	        printf(" *  |_____________________________________________\n");
	        printf("               \n");
	        printf(" *   *   *   *   *   *   *   *   *   *   *   *   *   * \n");   
	        printf("\nPress any key to continue");
	        getch();
	        system("cls");
	        
			profit=0;
	        ftotal=fopen("profit.txt","w");	
	        fprintf(ftotal,"%f",profit);	
	        fclose(ftotal);
}

float lastWeek_movie(float price[])
{
	printf("    List of movies for last week :\n\n");
	printf("________________________________\n");
	printf("|                  \n");
	printf("| 1) %s = RM%.2f      \n",movie[0],price[0]);
	printf("| 2) %s = RM%.2f      \n",movie[1],price[1]);
	printf("| 3) %s = RM%.2f      \n",movie[2],price[2]);
    printf("| 4) %s = RM%.2f      \n",movie[3],price[3]);
	printf("| 5) %s = RM%.2f      \n",movie[4],price[4]);
	printf("|__________________________________");
	printf("\n\nPress any key to continue");
	getch();
	system("cls");
	
	return price[0],price[1],price[2],price[3],price[4];
}

void save_movie(float price[], int confirm)
{
	
	do
	{
	system("cls");
	printf("Update name of movies for this week:\n\n");
	for(u=0;u<5;u++)
	{
	    scanf("%s",&movie[u]);
    }
			  	  	
	printf("\nRewrite the price for the latest price :\n\n");
	for(u=0;u<5;u++)
	{
	   scanf("%f",&price[u]);
    }
    
    system("cls");
    printf("List of movies:\n\n");
    printf("1) %s =RM%.2f\n",movie[0],price[0]);   
	printf("2) %s =RM%.2f\n",movie[1],price[1]);   
	printf("3) %s =RM%.2f\n",movie[2],price[2]);   
	printf("4) %s =RM%.2f\n",movie[3],price[3]);   
	printf("5) %s =RM%.2f\n",movie[4],price[4]);
	
	printf("\nConfirm to use this movie ? < press 0 to confirm > :");
	scanf("%d",&confirm);
	
    }while(confirm!=0);
	
	fmovie=fopen("movie.txt","w");
	fprintf(fmovie,"%s %s %s %s %s",movie[0],movie[1],movie[2],movie[3],movie[4]);
	fclose(fmovie);
	
    fmoney=fopen("money.txt","w");
	fprintf(fmoney,"%f %f %f %f %f",price[0],price[1],price[2],price[3],price[4]);	
	fclose(fmoney);
	
 	printf("\nPress any key to continue");
    getch();
 	system("cls");
}

void load_beverage(int totalFood[], int totalDrink[])
{
    
    fpopcorn=fopen("beverage.txt","r");
	fscanf(fpopcorn,"%d %d %d %d %d %d",&totalFood[0],&totalFood[1],&totalFood[2],&totalDrink[0],&totalDrink[1],&totalDrink[2]);	
	fclose(fpopcorn);

	printf("\n%s left :",nourishment[0]);
	printf("%d",totalFood[0]);
	printf("\n%s left :",nourishment[1]);
	printf("%d",totalFood[1]);
	printf("\n%s left :",nourishment[2]);
    printf("%d",totalFood[2]);
    printf("\n%s left :",beverage[0]);
	printf("%d",totalDrink[0]);
	printf("\n%s left :",beverage[1]);
	printf("%d",totalDrink[1]);
	printf("\n%s left :",beverage[2]);
	printf("%d",totalDrink[2]);
	
	printf("\n\nPress any key to continue"); 
    getch();
}

int refill_beverage(int chooseRefill, int i, int refill, int totalFood[], int totalDrink[], int food[], int drink[])
{
	printf("\n\nDo you want to refill ? < Press 1 to refill > :");
	scanf("%d",&chooseRefill);
	
	if(chooseRefill==1)
	{
	   for(i=0;i<3;i++)
       {	
	    	do
	    	{
	    	   printf("\n%s left = %d \n",nourishment[i],totalFood[i]);
	    	   printf("\nPlease refill < cannot exceed 100 > :");
	    	   scanf("%d",&refill);
	    	   totalFood[i]+=refill;
			}while(totalFood[i]!=100);
       }
    
       for(i=0;i<3;i++)
       {
	    		    	
	    	do
	    	{
	    	   printf("\n%s left = %d \n",beverage[i],totalDrink[i]);
	    	   printf("\nPlease refill < cannot exceed 100 > :");
	    	   scanf("%d",&refill);
	    	   totalDrink[i]+=refill;
			}while(totalDrink[i]!=100);

       } 
	}
	
    for(i=0;i<3;i++)
    {
		while(totalFood[i]<=10)
	    {	    	
	    	printf("\n\n%s is run out of stock !!!!!\n",nourishment[i]);
	    	
	    	do
	    	{
	    	   printf("\n%d left\n",totalFood[i]);
	    	   printf("\nPlease refill < cannot exceed 100 > :");
	    	   scanf("%d",&refill);
	    	   totalFood[i]+=refill;
			}while(totalFood[i]!=100);
		}
    }
    
    for(i=0;i<3;i++)
    {
		while(totalDrink[i]<=10)
	    {	    	
	    	printf("\n\n%s is run out of stock !!!!!\n",beverage[i]);
	    	
	    	do
	    	{
	    	   printf("\n%d left\n",totalDrink[i]);
	    	   printf("\nPlease refill < cannot exceed 100 > :");
	    	   scanf("%d",&refill);
	    	   totalDrink[i]+=refill;
			}while(totalDrink[i]!=100);
		}
   }
    fpopcorn=fopen("beverage.txt","w");
    fprintf(fpopcorn,"%d %d %d %d %d %d %d %d %d %d %d %d",food[0],food[1],food[2],drink[0],drink[1],drink[2],totalFood[0],totalFood[1],totalFood[2],totalDrink[0],totalDrink[1],totalDrink[2]);	
	fclose(fpopcorn); 
}

void animation(int q)
{
	system("COLOR 0D");
    printf("Press any key to start");
	getch();
	system("cls");

    for(u=0;u<5;u++)
	{
        for(q=0;q<4;q++)
		{
            printf("                                                 \n\n\n\n\n\n\n\n\n");
			printf("_________________________________________________________________\n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 |  \n");
			printf("   TV                                                            |                                \n");
          	printf("________   Ha                                                    |                  _______               \n");
	        printf("        |                         ,                              |                 |   |   |         \n");
	        printf(" \\ O /  |                         O                              |                 |   |___|___       \n");
	        printf("   |    |      Ha                /|\\                             |               ==|           |       \n");
        	printf("__/_\\___|                         |                              |                 |___________|                   \n");
        	printf("_________________________________/_\\_____________________________|__________________O________O___________________________________________________________\n"); 
        	system("cls");
		}
		
		for(q=0;q<4;q++)
		{
            printf("                                                 \n\n\n\n\n\n\n\n\n");
			printf("_________________________________________________________________\n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 |  \n");
			printf("   TV                                                            |                                \n");
          	printf("________                                                         |                  _______               \n");
	        printf("        |                         ,                              |                 |   |   |         \n");
	        printf(" \\ O /  |      Ha                 O                              |                 |   |___|___       \n");
	        printf("   |    |                        /|\\                             |               ==|           |       \n");
        	printf("__/_\\___| Ha                      |                              |                 |___________|                   \n");
        	printf("_________________________________/_\\_____________________________|__________________O________O___________________________________________________________\n"); 
        	system("cls");
		}
   }
   
    for(u=0;u<4;u++)
	{
        for(q=0;q<4;q++)
		{
            printf("                                                 \n\n\n\n\n\n\n\n\n");
			printf("_________________________________________________________________\n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 |  \n");
			printf("   TV                                                            |                                \n");
          	printf("________   Ha                  Im bored                          |                  _______               \n");
	        printf("        |                         ,                              |                 |   |   |         \n");
	        printf(" \\ O /  |                         O                              |                 |   |___|___       \n");
	        printf("   |    |      Ha                /|\\                             |               ==|           |       \n");
        	printf("__/_\\___|                         |                              |                 |___________|                   \n");
        	printf("_________________________________/_\\_____________________________|__________________O________O___________________________________________________________\n"); 
        	system("cls");
		}
		
		for(q=0;q<4;q++)
		{
            printf("                                                 \n\n\n\n\n\n\n\n\n");
			printf("_________________________________________________________________\n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 |  \n");
			printf("   TV                                                            |                                \n");
          	printf("________                       Im bored                          |                  _______               \n");
	        printf("        |                         ,                              |                 |   |   |         \n");
	        printf(" \\ O /  |      Ha                 O                              |                 |   |___|___       \n");
	        printf("   |    |                        /|\\                             |               ==|           |       \n");
        	printf("__/_\\___| Ha                      |                              |                 |___________|                   \n");
        	printf("_________________________________/_\\_____________________________|__________________O________O___________________________________________________________\n"); 
        	system("cls");
		}
   }

	for(u=0;u<13;u++)
	{
		    printf("                                                                                          \n");
		    printf("                                         <               >                               \n");
            printf("                                                     \n\n\n\n\n\n\n");
			printf("_________________________________________________________________\n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 |  \n");
			printf("   TV                                                            |                                \n");
          	printf("________                                                         |                  _______               \n");
	        printf("        |                         ,                              |                 |   |   |         \n");
	         printf(" \\ O /  |                         O                              |                 |   |___|___       \n");
	        printf("   |    |                        /|\\                             |               ==|           |       \n");
        	printf("__/_\\___|                         |                              |                 |___________|                   \n");
        	printf("_________________________________/_\\_____________________________|__________________O________O___________________________________________________________\n"); 
	        system("cls");
	}
	
	for(u=0;u<5;u++)
	{
			printf("                                                                                          \n");
		    printf("                                         < G             >                               \n");
            printf("                                                     \n\n\n\n\n\n\n");
			printf("_________________________________________________________________\n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 |  \n");
			printf("   TV                                                            |                                \n");
          	printf("________                                                         |                  _______               \n");
	        printf("        |                         ,  Off                         |                 |   |   |         \n");
	        printf("        |                         O                              |                 |   |___|___       \n");
	        printf("        |                      +=-|\\                             |               ==|           |       \n");
        	printf("________|                         |                              |                 |___________|                    \n");
        	printf("_________________________________/_\\_____________________________|__________________O________O___________________________________________________________\n"); 
	        system("cls");
	}
	
		for(u=0;u<5;u++)
	{
		    printf("                                                                                          \n");
		    printf("                                         < Ge             >                               \n");
			printf("                                                      \n\n\n\n\n\n\n");
			printf("_________________________________________________________________\n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 |  \n");
			printf("   TV                                                            |                                \n");
          	printf("________                                                         |                  _______               \n");
	        printf("        |                         ,  Off                         |                 |   |   |         \n");
	        printf("        |                         O                              |                 |   |___|___       \n");
	        printf("        |                      +=-|\\                             |               ==|           |       \n");
        	printf("________|                         |                              |                 |___________|                    \n");
        	printf("_________________________________/_\\_____________________________|__________________O________O___________________________________________________________\n"); 
	        system("cls");
	}
	
		for(u=0;u<5;u++)
	{
		    printf("                                                                                          \n");
		    printf("                                         < Gem           >                               \n");
			printf("                                                     \n\n\n\n\n\n\n");
			printf("_________________________________________________________________\n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 |  \n");
			printf("   TV                                                            |                                \n");
          	printf("________                                                   ______|                  _______               \n");
	        printf("        |                                              ,  |      |                 |   |   |         \n");
	        printf("        |                                              O__| Door |                 |   |___|___       \n");
	        printf("        |                                             /|  |      |               ==|           |       \n");
        	printf("________|                                              |  |      |                 |___________|                    \n");
        	printf("______________________________________________________/_\\_|______|__________________O________O___________________________________________________________\n"); 
	        system("cls");
	}
	
		for(u=0;u<5;u++)
	{
			printf("                                                                                          \n");
		    printf("                                         < Gemp          >                               \n");
			printf("                                                     \n\n\n\n\n\n\n");
			printf("_________________________________________________________________\n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 |  \n");
			printf("   TV                                                            |                                \n");
          	printf("________                                                   ______|                  _______               \n");
	        printf("        |                                              ,  |      |                 |   |   |         \n");
	        printf("        |                                              O__| Door |                 |   |___|___       \n");
	        printf("        |                                             /|  |      |               ==|           |       \n");
        	printf("________|                                              |  |      |                 |___________|                    \n");
        	printf("______________________________________________________/_\\_|______|__________________O________O___________________________________________________________\n"); 
	        system("cls");
	}
	
		for(u=0;u<5;u++)
	{
			printf("                                                                                          \n");
		    printf("                                         < Gempa         >                               \n");
			printf("                                                     \n\n\n\n\n\n\n");
			printf("_________________________________________________________________\n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 |  \n");
			printf("   TV                                                            |                                \n");
          	printf("________                                                         |                  _______               \n");
	        printf("        |                                                        |  ,              |   |   |         \n");
	        printf("        |                                                        |__O              |   |___|___       \n");
	        printf("        |                                                        |  |\\           ==|           |       \n");
        	printf("________|                                                        |  |              |___________|                    \n");
        	printf("_________________________________________________________________|_/_\\______________O________O___________________________________________________________\n"); 
	        system("cls");
	}
	
		for(u=0;u<5;u++)
	{
			printf("                                                                                          \n");
		    printf("                                         < Gempak        >                               \n");
			printf("                                                     \n\n\n\n\n\n\n");
			printf("_________________________________________________________________\n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 |  \n");
			printf("   TV                                                            |                                \n");
          	printf("________                                                         |                  _______               \n");
	        printf("        |                                                        |  ,              |   |   |         \n");
	        printf("        |                                                        |__O              |   |___|___       \n");
	        printf("        |                                                        |  |\\           ==|           |       \n");
        	printf("________|                                                        |  |              |___________|                    \n");
        	printf("_________________________________________________________________|_/_\\______________O________O___________________________________________________________\n"); 
	        system("cls");
	}
	
		for(u=0;u<5;u++)
	{
			printf("                                                                                          \n");
		    printf("                                         < Gempak C      >                               \n");
			printf("                                                     \n\n\n\n\n\n\n");
			printf("_________________________________________________________________\n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 |  \n");
			printf("   TV                                                            |                                \n");
          	printf("________                                                         |                  _______               \n");
	        printf("        |                                                        |                 |   | O |         \n");
	        printf("        |                                                        |                 |   |_\\_|___       \n");
	        printf("        |                                                        |               ==|           |       \n");
        	printf("________|                                                        |                 |___________|                    \n");
            printf("_________________________________________________________________|__________________O________O___________________________________________________________\n"); 
	        system("cls");
	}
	
		for(u=0;u<5;u++)
	{
			printf("                                                                                          \n");
		    printf("                                         < Gempak Ci     >                               \n");
		    printf("                                                     \n\n\n\n\n\n\n");
			printf("_________________________________________________________________\n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 |  \n");
			printf("   TV                                                            |                                \n");
          	printf("________                                                         |                  _______               \n");
	        printf("        |                                                        |                 |   | O |         \n");
	        printf("        |                                                        |                 |   |_\\_|___       \n");
	        printf("        |                                                        |               ==|           |       \n");
        	printf("________|                                                        |                 |___________|                    \n");
            printf("_________________________________________________________________|__________________O________O___________________________________________________________\n"); 
	        system("cls");
	}
	
		for(u=0;u<5;u++)
	{
			printf("                                                                                          \n");
		    printf("                                         < Gempak Cin    >                               \n");
			printf("                                                     \n\n\n\n\n\n\n");
			printf("_________________________________________________________________\n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 |  \n");
			printf("   TV                                                            |                                     \n");
          	printf("________                                                         |                                                      _______               \n");
	        printf("        |                                                        |                                                     |   | O |         \n");
	        printf("        |                                                        |                                                     |   |_\\_|___       \n");
	        printf("        |                                                        |                                               ) ) ==|           |       \n");
        	printf("________|                                                        |                                                     |___________|                    \n");
        	printf("_________________________________________________________________|______________________________________________________O________O_______________________\n"); 
	        system("cls");
	}
	
		for(u=0;u<5;u++)
	{
			printf("                                                                                          \n");
		    printf("                                         < Gempak Cine   >                               \n");
			printf("                                                     \n\n\n\n\n\n\n");
			printf("_________________________________________________________________\n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 |  \n");
			printf("   TV                                                            |                                     \n");
          	printf("________                                                         |                                                      _______               \n");
	        printf("        |                                                        |                                                     |   | O |         \n");
	        printf("        |                                                        |                                                     |   |_\\_|___       \n");
	        printf("        |                                                        |                                               ) ) ==|           |       \n");
        	printf("________|                                                        |                                                     |___________|                    \n");
        	printf("_________________________________________________________________|______________________________________________________O________O_______________________\n");  
        	system("cls");
	}
	
		for(u=0;u<5;u++)
	{
			printf("                                                                                          \n");
		    printf("                                         < Gempak Cinem  >                               \n");
			printf("                                                     \n\n\n\n\n\n\n");
			printf("_________________________________________________________________\n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 |  \n");
			printf("   TV                                                            |                                     \n");
          	printf("________                                                         |                                                                            \n");
	        printf("        |                                                        |                                                                         \n");
	        printf("        |                                                        |                                                                           \n");
	        printf("        |                                                        |                                                                     \n");
        	printf("________|                                                        |                                                                            \n");
        	printf("_________________________________________________________________|_______________________________________________________________________________________\n");  
        	system("cls");
	}
	
		for(u=0;u<5;u++)
	{
			printf("                                                                                          \n");
		    printf("                                         < Gempak Cinema >                               \n");
			printf("                                                     \n\n\n\n\n\n\n");
			printf("_________________________________________________________________\n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 | \n");
			printf("                                                                 |  \n");
			printf("   TV                                                            |                                     \n");
          	printf("________                                                         |                                                                            \n");
	        printf("        |                                                        |                                                                         \n");
	        printf("        |                                                        |                                                                           \n");
	        printf("        |                                                        |                                                                     \n");
        	printf("________|                                                        |                                                                            \n");
        	printf("_________________________________________________________________|__________________________________________________________________________________________\n");   
        	system("cls");
	}
	
	for(q=0;q<13;q++) 	
       {
       	printf("\n\n\n\n\n\n\n");
       	printf("\n\n\n\n\n                                 After 30 minute\n\n");
       	printf("\n\n\n\n\n\n\n\n\n\n");
       	system("cls");
	   }
	
	for(u=0;u<4;u++)
	{
		for(q=0;q<4;q++)
		{
	   	    printf("                                                                                                                                    |\n");
	        printf("                                         < Gempak Cinema >                                                                          |\n");
	        printf("                                                                                                                              Ticket|          \n");
	        printf("                                                                                                                               Booth|         \n");  	
		    printf("                                                                                                       ______                 ______|            \n");
			printf(" SCREEN                                                                                               |      |               |      |      \n");			
			printf("________                                                                                              |      |               | ==== |       \n");
			printf("        |     *                                                                                       | Exit |          O    |      |     \n");
	    	printf("        |   *                                                                   Yeay       @          |      |         /|-{$}| ==== |        \n");
		    printf("        |      *                                                                         O_|          |      |          |    |      |        \n");
		    printf("        | *                                                                       ,     /| |  ________|______|_________/_\\___|______|                     \n");
		    printf("        |    *                                                                  \\ O /    |   |                                      |        \n");
		    printf("        |                                                        \\    /           |    _/ \\__|                                      |              \n");
		    printf("        |  *   *                                                                  |   |                                             |     \n");
			printf("        |                                                                @ o   __/_\\__|                                             |     \n");
			printf("        | *   *                                                     O    |-|- |                                                     |        \n");
		    printf("        |                                     \\      /          [0]/|\\  __/_\\_|                                                     |            \n");
			printf("        |  *    *                                          O        |   |                                                           |           \n");
			printf("        |     *                                           /|\\    __/_\\__|                                                           |           \n");
          	printf("        |  *                                    \\ O /      |    |                                                                   |                 \n");
	        printf("        |      *                                  |     __/_\\___|                                                                   |                      \n");
	        printf("        | *                                       |    |                                                                            |                     \n");
	        printf("        |     *                                 _/_\\___|                                                                            |          \n");
        	printf("________|   *                                  |                                                                                    |        \n");
        	printf("_______________________________________________|____________________________________________________________________________________|    \n");

            system("cls");
        }
        	
		for(q=0;q<4;q++)
		{
	   	    printf("                                                                                                                                    |\n");
	        printf("                                         < Gempak Cinema >                                                                          |\n");
	        printf("                                                                                                                              Ticket|          \n");
	        printf("                                                                                                                               Booth|         \n");  	
		    printf("                                                                                                       ______                 ______|            \n");
			printf(" SCREEN                                                                                               |      |               |      |      \n");			
			printf("________                                                                              \\    /          |      |               | ==== |       \n");
			printf("        |          *                                                                                  | Exit |          O    |      |     \n");
	    	printf("        |  *    *                                                                          @          |      |         /|-{$}| ==== |        \n");
		    printf("        |     *                                                                          O_|          |      |          |    |      |        \n");
		    printf("        |   *    *                                                                ,     /| |  ________|______|_________/_\\___|______|                     \n");
		    printf("        |                                                                       \\ O /    |   |                                      |        \n");
		    printf("        |    *                                                           Yeay     |    _/ \\__|                                      |              \n");
		    printf("        |                                                                         |   |                                             |     \n");
			printf("        |  *     *                                                       @ o   __/_\\__|                                             |     \n");
			printf("        |      *                                       \\    /       O    |-|- |                                                     |        \n");
		    printf("        |   *                                                   [0]/|\\  __/_\\_|                                                     |            \n");
			printf("        |        *                               Yeay      O        |   |                                                           |           \n");
			printf("        |  *                                              /|\\    __/_\\__|                                                           |           \n");
          	printf("        |                                       \\ O /      |    |                                                                   |                 \n");
	        printf("        |     *                                   |     __/_\\___|                                                                   |                      \n");
	        printf("        |                                         |    |                                                                            |                     \n");
	        printf("        |    *     *                            _/_\\___|                                                                            |          \n");
        	printf("________|                                      |                                                                                    |        \n");
        	printf("_______________________________________________|____________________________________________________________________________________|    \n");

            system("cls");
        }
        
	}
    
   	        printf("                                                                                                                                    |\n");
	        printf("                                         < Gempak Cinema >                                                                          |\n");
	        printf("                                                                                                                              Ticket|          \n");
	        printf("                           -------For a better movie experience------                                                          Booth|         \n");  	
		    printf("                                                                                                       ______                 ______|    \n");
			printf(" SCREEN                                                                                               |      |               |      |      \n");			
			printf("________                                                                                              |      |               | ==== |       \n");
			printf("        |  *   *  *                                                                                   | Exit |          O    |      |     \n");
	    	printf("        |   *   *                                                                          @          |      |         /|-{$}| ==== |        \n");
		    printf("        |     *                                                                  Yeay    O_|          |      |          |    |      |        \n");
		    printf("        | *        *                                                              ,     /| |  ________|______|_________/_\\___|______|                     \n");
		    printf("        |      *                                                                \\ O /    |   |                                      |        \n");
		    printf("        |  *       *                                                              |    _/ \\__|                                      |              \n");
		    printf("        |     *                                                                   |   |                                             |     \n");
			printf("        |  *     *                                                       @ o   __/_\\__|                                             |     \n");
			printf("        | *     *                                                   O    |-|- |                                                     |        \n");
		    printf("        |   *  *                                                [0]/|\\  __/_\\_|                                                     |            \n");
			printf("        |    *    *                                        O        |   |                                                           |           \n");
			printf("        | *     *                                         /|\\    __/_\\__|                                                           |           \n");
          	printf("        |     *                                 \\ O /      |    |                                                                   |                 \n");
	        printf("        |  *    *                                 |     __/_\\___|                                                                   |                      \n");
	        printf("        | *  *   *                                |    |                                                                            |                     \n");
	        printf("        |      *                                _/_\\___|                                                                            |          \n");
        	printf("________|   *     *                            |                                                                                    |        \n");
        	printf("_______________________________________________|____________________________________________________________________________________|    \n");
             
            printf("\n\nPress any key to continue");
            getch();
            system("cls");
   
}
