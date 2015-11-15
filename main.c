/*****************************************************************************
 * Copyright (C) V. JIGNESH SHAH     shahjj14.it@coep.ac.in
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/




/* This is the main.c file which shows the MAINMENU , MOVIES SEATMAP for boking the show  
   and create or login with your username and password */

#include "bookings.h"

/* Global Arrays 
  These are used throghout the program */	

char M1[128] = { "PYAR KA PUNCHNAMA:2" };
char M2[128] = { "PREM RATAN DHAN PAYO" };
char M3[128] = { "THE MARTIAN" };

char M1_timing1[8] = {"12:30"};
char M1_timing2[8] = {"03:30" };
char M1_timing3[8] = {"06:30"};
char M2_timing1[8] = {"11:30"};
char M2_timing2[8] = {"01:30"};
char M2_timing3[8] = {"05:30"};
char M3_timing1[8] = {"11:00"};
char M3_timing2[8] = {"04:00"};


int M1_T1_bookings[91] = { 0 };
int M1_T2_bookings[91] = { 0 };
int M1_T3_bookings[91] = { 0 };
		
int M2_T1_bookings[91] = { 0 };
int M2_T2_bookings[91] = { 0 };
int M2_T3_bookings[91] = { 0 };
		
int M3_T1_bookings[91] = { 0 };
int M3_T2_bookings[91] = { 0 };


int main() {
	int j = NUM;
	system("clear");
	printf ("\t\t\t\t\t****************************************************\n");
	printf ("\t  \n");
	printf ("\t\t\t\t\t\t\t    * Welcome To *\n");
	printf ("\t\t\t\t\t\t\t* Movie Ticket Booking *\n\n\n");
	printf ("\t\t\t\t\t\t    ******** GALAXY CINEMAS ********\n");
	printf ("\t  \n");	
	printf ("\t\t\t\t\t*****************************************************\n");
	galaxy();
	while(j){
		j--;
	}
	mainmenu();
	return 0;
}

/* Shows The MAIN MENU of the project 
  
   View the current movies
   Boook Tickets
   Admin Access
   Exit
*/
void mainmenu()
{
	system("clear");
	int choice, opt;
	time_t now = time(NULL);
  	struct tm *t = localtime(&now);
 	char p[10];
	printf ("\n\n\t^^^^^^^^^^^^^^^^^^^^^ MAIN MENU ^^^^^^^^^^^^^^^^^^^^^\n\n");
	printf ("\t 1. View NOW SHOWING\n\n");
	printf ("\t 2. Book Tickets\n\n");
	printf ("\t 3. ADMIN LOGIN\n\n\n");
	printf ("\t 4. Quit Booking\n\n");
	printf ("\n\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");	
	printf ("\n\n\tEnter your option : ");
	scanf("%d", &choice);
	switch(choice)
	{
	case 1:
		viewshows();
		break;
	case 2: /*Showing the Movies that you want to book for TODAYS date*/
		sprintf(p,"%d/%d/%d",t->tm_mday,t->tm_mon +1, t->tm_year +1900);
		printf("\n\t^^^^^^^^^^^^^^^^^^^^^ BOOK TICKETS ^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n");
		printf("\t\tShows Showing for TODAY : %s \n\n", p);
		printf("\t\n\n Book for : \n\n");
		printf("\t 1. %s \n\n", M1);
		printf("\t 2. %s \n\n", M2);
		printf("\t 3. %s \n\n", M3);
		printf("\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
		printf("\tEnter Your Option : ");
		scanf("%d", &opt);
		switch(opt) {
			case 1: strcpy(c.show.movie, M1);
				break;
			case 2: strcpy(c.show.movie, M2);
				break;
			case 3: strcpy(c.show.movie, M3);
				break;
			default:printf("\t\tFailed: Wrong choice entered\n\n\n");
				exit(1);	
				break;
		}
		showtiming(opt);
		break;
	case 3: /* Asking the Admin password to acess admin functions */
		printf("\n\t\t***********************\n");
		printf("\t\t***** ADMIN LOGIN *****\n\n");
		char str[20],d;
		int x=0;
		printf("Enter ADMIN Password : ");
		getchar();
		while (x<=9){
    			str[x] = getch();
    			d = str[x];
    			if(d =='\n')
    				break;
    			else 
    				printf("*");
    			x++;
    			
		}
		str[x]='\0';
		x=0;
		while (1) {
			if(strcmp("password", str) == 0) {
			printf(" \nPassword Matched\n ");
			printf(" 	_______	 ______	_______   ____	        \n");
			printf(" 	|  |  |	 |    |	   |     |      |    | \n");
			printf("	|  |  |	 |____|	   |	 |	|----|  \n" );                
			printf(" 	|     |  |    |    |	 |____	|    | \n");
			printf(" 					    \n"); 
			admin();
			sleep(2);
		}
		else {
			printf(" \nEntered password is wrong\n\n");
			printf(" Returning to main menu \n");
			sleep(1);
			mainmenu();
		}
		}
		break;	
	case 4:
	printf("\n\t__________________________________________________________________\n\n\n");
	printf("\t Thank you for using Movie Ticket Booking ... \n\n");
	printf("\n\t__________________________________________________________________\n\n");
	exit(0);
	default:
		printf("Invalid choice\n\n");
		mainmenu();
	 	break;
	 }	
}

/*-----------------View Shows-----------------------*/
void viewshows()
{ 
	system("clear");
	int d;
	printf("\n\t^^^^^^^^^^^^^^^^^^^^ NOW SHOWING ^^^^^^^^^^^^^^^^^\n");
	printf("\t\t\n\n HINDI");
	printf("\n\n\t 1.%s\n\n\n", M1);
	printf("\n\n\t 2.%s\n\n\n", M2);
	printf("\t\t\n\n ENGLISH\n\n");
	printf("\n\n\t 3.%s\n\n\n", M3);
	printf("\n\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	printf("\n\tEnter 0 to Exit From This Menu : ");
	scanf("%d", &d);
	if(d == 0)
		mainmenu();
	else
		printf("Invalid Entry\n");
		viewshows();		
}
/*--------------TIMINGS OF SHOWS ------------*/
void showtiming(int opt) {

	if (opt == 1){
		int showtime;
		printf("\t\n Timings : \n\n");
		printf("\t 1.  %s\n\n", M1_timing1);
		printf("\t 2.  %s\n\n", M1_timing2);
		printf("\t 3.  %s\n\n", M1_timing3);
		printf("\tEnter Your Show : ");
		/* book the tickets of that show accordingly and store it in the structure of that customer */
		scanf("%d", &showtime);
		
		/* Showing your movie according to the option entered */
		switch(showtime) {
		case 1: strcpy(c.show.timing, M1_timing1);
			break;
		case 2: strcpy(c.show.timing, M1_timing2);
			break;
		case 3: strcpy(c.show.timing, M1_timing3);
			break;
		default : printf("Failed: Wrong Input\n");
			showtiming(1);
			break;
		}
		/* Dispalying the seats, according to your movie and show */
		seatdisp(opt, showtime);
		
	}	
	if (opt == 2){
		int showtime;
		printf("\t\n Timings : \n\n");
		printf("\t 1.  %s\n\n", M2_timing1);
		printf("\t 2.  %s\n\n", M2_timing2);
		printf("\t 3.  %s\n\n", M2_timing3);
		printf("\tEnter Your Show : ");
		scanf("%d", &showtime);
		switch(showtime) {
		case 1: strcpy(c.show.timing, M2_timing1);
			break;
		case 2: strcpy(c.show.timing,M2_timing2);
			break;
		case 3: strcpy(c.show.timing, M2_timing3);
			break;
		default : printf("Failed: Wrong Input\n");
			showtiming(2);
			break;
		}
		/* Dispalying the seats, according to your movie and show */
		seatdisp(opt, showtime);
	}	
	if (opt == 3) {
		int showtime;
		printf("\t\n Timings : \n\n");
		printf("\t 1.   %s\n\n", M3_timing1);
		printf("\t 2.   %s\n\n", M3_timing2);
		printf("\tEnter Your Show : ");
		scanf("%d", &showtime);
		switch(showtime) {
		case 1: strcpy(c.show.timing, M3_timing1);
			break;
		case 2: strcpy(c.show.timing, M3_timing2);
			break;
		default : printf("Failed: Wrong Input\n");
			showtiming(3);
			break;
		}
		/* Dispalying the seats, according to your movie and show */
		seatdisp(opt, showtime);	
	}
	printf("\n\n\n");
	/* Funtion call to save all the details of the customer */
	savecustomer();
	
}	
/* ----------- DISPLAYING SEAT MAP ------------*/ 
/* It takes the	Movie name and timing as arguments 
 * Asks the user no. of seats he wants to book 
 * Stores it in the customers structure
 * Reads from the file , how many seats are booked and how many are available 
 * mapshow() is called to see the seats available in a good interface */ 
void seatdisp(int opt, int showtime){
	confirmation();	
	int p, t;
	printf("\n\n\t\tEnter the No. of seats to be booked  :  ");
	scanf("%d", &cust);
		if(cust > 90){
			printf("\t\tInvalid Input\n");
			exit(0);
			
		}
		c.seats = cust;
	/* Searching for your movie acccording too the timing of the show */ 
	switch(opt){
		case 1: printf("\t\t\t\n\n Displaying Seats For %s ", M1);
			if(showtime == 1) {
				printf(" \t\t\t %s \n", M1_timing1);
				FILE *ptr = fopen("M1_T1.txt", "a+");
				while(fscanf(ptr,"%d %d", &p, &t)!=EOF)
					M1_T1_bookings[p] = t;
				fclose(ptr);
				mapshow(M1_T1_bookings, cust, opt, showtime);
			}	
			else if(showtime == 2) {
				printf(" \t\t\t %s \n", M1_timing2);
				FILE *ptr = fopen("M1_T2.txt", "a+");
				while(fscanf(ptr,"%d %d", &p, &t)!=EOF)
					M1_T2_bookings[p] = t;
				fclose(ptr);
				mapshow(M1_T2_bookings,cust, opt, showtime );
			}
			else if(showtime == 3) {
				printf(" \t\t\t %s \n", M1_timing3);
				FILE *ptr = fopen("M1_T3.txt", "a+");
				while(fscanf(ptr,"%d %d", &p, &t)!=EOF)
					M1_T3_bookings[p] = t;
				
				fclose(ptr);
				mapshow(M1_T3_bookings,cust, opt, showtime);
			}
			printf("\t--------------------------------------------------------------------\n\n");
			printf("\tTotal Booked Seats: %d\n\n", cust);
			break;
				
	
		case 2: printf("\t\t\t Displaying Seats For %s \n", M2 );
			if(showtime == 1) {
				printf(" \t\t\t %s \n", M2_timing1);
				FILE *ptr = fopen("M2_T1.txt", "a+");
				while(fscanf(ptr,"%d %d", &p, &t)!=EOF)
					M2_T1_bookings[p] = t;
				fclose(ptr);
				mapshow(M2_T1_bookings,cust, opt, showtime);
			}	
			else if(showtime == 2) {
				printf(" \t\t\t %s \n", M2_timing2);
				FILE *ptr = fopen("M2_T2.txt", "a+");
				while(fscanf(ptr,"%d %d", &p, &t)!=EOF)
					M2_T2_bookings[p] = t;
				
				fclose(ptr);
				mapshow(M2_T2_bookings,cust, opt, showtime);
			}	
			else if(showtime == 3) {
				printf(" \t\t\t %s \n", M2_timing3);
				FILE *ptr = fopen("M2_T3.txt", "a+");
				while(fscanf(ptr,"%d %d", &p, &t)!=EOF)
					M2_T3_bookings[p] = t;
				
				fclose(ptr);
				mapshow(M2_T3_bookings,cust, opt, showtime);
			}
			printf("\t--------------------------------------------------------------------");
			printf("\n\tTotal Booked Seats: %d\n\n", cust);
			break;
			
		case 3: printf("\t\t\t Displaying Seats For %s \n", M3);
			if(showtime == 1) {
				printf(" \t\t\t %s \n", M3_timing1);
				FILE *ptr = fopen("M3_T1.txt", "a+");
				while(fscanf(ptr,"%d %d", &p, &t)!=EOF)
					M3_T1_bookings[p] = t;
				
				fclose(ptr);
				mapshow(M3_T1_bookings,cust, opt, showtime);
			}
			else if(showtime == 2) {
				printf(" \t\t\t %s \n", M3_timing2);
				FILE *ptr = fopen("M3_T2.txt", "a+");
				while(fscanf(ptr,"%d %d", &p, &t)!=EOF)
					M3_T2_bookings[p] = t;
				
				fclose(ptr);
				mapshow(M3_T2_bookings,cust, opt, showtime);
			}	
			printf("\t--------------------------------------------------------------------\n\n");
			printf("\n\tTotal Booked Seats : %d\n\n", cust);
			break;	

	}
			
	
}
/* INPUT : The array associated with that show, no. of seats you want to book , movie and showtiming */
/* OUTPUT : Stores the seat numbers user entered in the particular shows array */
/* Calculates the rate and tax */
void mapshow(int bookings[],int cust, int opt, int showtime) {
	FILE *BOOKINGS;
	int l;
        int seat = 1;
        int seatno[8];
        int d = 0;
        int e = 1;
        int i, j;
        printf("-----------------------------------------------------------------------------------------------------------\n\n");
        printf("----------------------------------------SCREEN THIS WAY----------------------------------------------------\n\n\n\n\n\n");
        	  
        	
     	printf("                             ************* SILVER - Rs. 90 *******************                                  \n\n\t");
               
        for(i=1;i<=3;i++) {
		for(j=1;j<=10;j++) { 
                	int y = (i - 1)* 10 + (j);
                	if(bookings[y])       
                	        printf("BOOKED    ");
				else 
				printf("|_|-%3d   ", seat);
        		seat++;
                }
                printf("\n\t");
        }
          	printf("\n\n");
 		
	printf("                            ************* GOLD - Rs. 120*******************                                  \n\n\t");
	for(i=4;i<=6;i++) {
        	for(j=1;j<=10;j++) { 
                	int y = (i - 1)* 10 + (j);
                	     if(bookings[y])       
                	     printf("BOOKED    ");
			     else 
		             printf("|_|-%3d   ", seat);
        		seat++;
                }
                printf("\n\t");
        }
        printf("\n\n");
         printf("                           ************* DIAMOND Rs. 150*******************                                  \n\n\t");
	for(i=7;i<=9;i++) {
        	for(j=1;j<=10;j++) {
                	 int y = (i - 1)* 10 + (j);
                	 	if(bookings[y])       
                	 	printf("BOOKED    ");
				else 
				printf("|_|-%3d   ", seat);	
                	seat++;
                }
                printf("\n\t");
         }
     	printf("\n\n\n\n");
  
          	
        int sea = 1;
        printf("\tEnter your seat number(s) : \n\n");
        for(l = 0; l < cust; l++) {
        	printf("\t\t\tSeat No: %d of %d : ", sea++, cust);
          	scanf("%d", &seatno[l]);
          	if(seatno[l] > 90 || seatno[l] < 0) {
          		printf("\n\n\t\tWrong seat Numbers Entered \n");
          		exit(0);
          	}
          	if( !bookings[seatno[l]] )
			bookings[seatno[l]] = 1;          		
        		else {
        			printf("\tSorry, Ticket already booked\n\t");
        			sea--;
        			l--;  		
        		}
             	}
             	printf("\t--------------------------------------------------------------------\n\n");
        //Calculate the amount according to the class
        //store the ammount in the structure
        //Add the TAX accordingly
         if(seatno[0] <= 30) {
          	c.rate = (cust * 90.00);
          }
          else if(seatno[0] >= 30 && seatno[0] <= 60) {
          	c.rate = (cust * 120.00);
          }
          else if (seatno[0] >= 60 && seatno[0] <= 90) {
          	c.rate = (cust * 150.00);
          }	
          c.tax = cust * 8.92;	
          c.amount = c.rate + c.tax;	
          
	/* store those seat numbers in that customer's structure */		
	for (l = 0; l < cust; l++) {
			printf("%s", c.show.timing);         
          		c.show.seatno[d] = seatno[l];
          		d++;
        }
        
        
        /* Confirming to proceed for payment Procedure */
        checkout();
        
        
        /* Login or create your acccount TO COMPLETE YOUR BOOKING */
        userid_password();
     	
     	
     	/* Storing the seat numbers in their respective booking files */ 	    	
	/* Searching the movie and its showtime by a switch and store it in a file */
	if(opt == 1) {
      		if(showtime == 1) {
          		BOOKINGS = fopen("M1_T1.txt", "w");
			while(e < 91) {
          			fprintf(BOOKINGS,"%d %d\n",e, bookings[e]);
          			e++;
          		}
			fclose(BOOKINGS);
		}	
		else if(showtime == 2) {
			BOOKINGS = fopen("M1_T2.txt", "w");
			while(e < 91) {
          			fprintf(BOOKINGS,"%d %d\n",e, bookings[e]);
          			e++;
			}
			fclose(BOOKINGS);
		}
		else if (showtime == 3) {
			BOOKINGS = fopen("M1_T3.txt", "w");
			while(e < 91) {
          			fprintf(BOOKINGS,"%d %d\n",e, bookings[e]);
	 			e++;
          		}
			fclose(BOOKINGS);
		}
	}
          	
	if(opt == 2) {
          	if(showtime == 1) {
          		BOOKINGS = fopen("M2_T1.txt", "w");
			while(e < 91) {
          			fprintf(BOOKINGS,"%d %d\n",e, bookings[e]);
          			e++;
          		}
			fclose(BOOKINGS);
		}	
		else if(showtime == 2) {
			BOOKINGS = fopen("M2_T2.txt", "w");
			while(e < 91) {
          			fprintf(BOOKINGS,"%d %d\n",e, bookings[e]);
          			e++;
			}
				fclose(BOOKINGS);
		}	
		else if (showtime == 3) {
			BOOKINGS = fopen("M2_T3.txt", "w");
			while(e < 91) {
          			fprintf(BOOKINGS,"%d %d\n",e, bookings[e]);
          			e++;
          		}
				fclose(BOOKINGS);
		}
	}
        if(opt == 3) {
          	if(showtime == 1) {
          		BOOKINGS = fopen("M3_T1.txt", "w");
			while(e < 91) {
          			fprintf(BOOKINGS,"%d %d\n",e, bookings[e]);
          			e++;
          		}
				fclose(BOOKINGS);
		}	
		else if(showtime == 2) {
			BOOKINGS = fopen("M3_T2.txt", "w");
			while(e < 91) {
          			fprintf(BOOKINGS,"%d %d\n",e, bookings[e]);
          			e++;
			}
			fclose(BOOKINGS);
			}
		}		          	          	
}


/* Confirming the booking procedure from the user as tickets once booked cannot be cancelled */
void confirmation() {
		char c;
		printf("\n\n\n----------------------------------------WARNING------------------------------------------------\n\n");
		printf("\n\nAre you sure you want to proceed to Booking \n\n");
		printf("\t\t**********--------ONCE BOOKED TICKETS CANNOT BE CANCELLED------------***********\n\n");
		printf("\t\t|||||| SINCE TICKETS ONCE BOOKED ARE DEEMED AS SOLD ||||||\n\n"); 
		printf("\t\t|||||| THEY CANNOT BE  EXCHANGED , REFUNDED OR CANCELLED ||||||\n\n");
		printf("\t\t\t\tYES (y) or NO(n) :  ");
		scanf(" %c", &c);
			if(c == 'y' || 'Y')
				return;
			else if (c == 'n' || 'N'){
				printf(" Returning to main menu ");
				mainmenu();		
			}
			else {
				printf("Please Select the Correct option \n\n");
				confirmation();
			}
}	
/* Confirming for Proceeding for Paymnet procedure */
void checkout(){
	int finale;
	printf("\t\tAre you sure YOU want to Proceed TO Payment :: \t\n\n\n");
	printf("\t\t\t\t1. YES \n\n");
	printf("\t\t\t\t2. NO , Return to main menu\t");
	scanf("%d", &finale);
	if (finale == 1){
		printf("\n\n\n");
		return;
	}
	else if (finale == 2){
		mainmenu(); 
	}	
	else {
		printf("\t\t\tWrong Choice \n\n");
		checkout();
	}
}

/* This function allows you to login to your username and password */
/* And if you dont have an acoount you can create one and store it in the file user.txt */


void userid_password() {
	printf("\t1. CREATE ACCOUNT\n\n");
	printf("\t2. LOGIN ACCOUNT \n\n");
	printf("\t3. CANCEL BOOKING AND EXIT\n\n");
	int cas, f;
	int w = 1;
	char name[16] , password1[16], password2[16];
	scanf("%d", &cas);
	FILE *USERS;
	USERS = fopen("user.txt", "a+");
	switch(cas) {
		case 1 : 
			printf("\t\tEnter you Username :");
			scanf("%s", c.username);
			printf("\n\t\tEnter your password : ");
			char d;
			int x = 0;
			getchar();
			/* Code for Encrypting the password us	er has entered */
			while (x <= 9){
    				password1[x] = getch();
    				d = password1[x];
    				if(d =='\n')
    					break;
    				else 
    					printf("*");
    				x++;	
			}
			password1[x]='\0';
			
			printf("\t\tEnter your password again :");
			char l;
			int y = 0;
			while (y <= 9){
    				password2[y] = getch();
    				l = password2[y];
    				if(l == '\n')
    					break;
    				else 
    					printf("*");
    				y++;	
			}
			password2[y] = '\0';
			if( strcmp (password1, password2) == 0) {
				strcpy(c.password, password1);
			}
			else {
				printf("\t\tPasswords did not match.. TRY AGIAN\n\n");
				userid_password();
			}
			fprintf(USERS, "%s \t\t\t %s\n", c.username, c.password );
			printf("\t--------------------------------------------------------------------\n\n");
			printf("\t\tYou have sucessfully created your account \n\n");
			printf("\t--------------------------------------------------------------------\n\n");
			fclose(USERS);
			break;
			
		case 2 : 
			while(1)
			{
			printf("\n\n\tEnter your username: ");
			scanf("%s", name);
			printf("\n\n\tEnter your password: ");
			char d;
			int x = 0;
			getchar();
			/* Code for Encrypting the password user has entered */
			while (x <= 9){
    				password1[x] = getch();
    				d = password1[x];
    				if(d =='\n')
    					break;
    				else 
    					printf("*");
    				x++;	
			}
			password1[x]='\0';

			while(fscanf(USERS, "%s%s", c.username, c.password) != EOF) {
			f = strcmp(c.username, name);
			l = strcmp(c.password, password1);
		
				if(f == 0 && l == 0){
					printf("\tLogin Successful\n\n");
					return;
				}
			}
			printf("\tWrong Username or password\n\n");
			printf("\tEnter again\n:");
			w++;
				if(w == 3) {
					printf("\tTOO MANY ATTEMPTS\n");
					printf("\tEXITING . . . . .\n\n\n\n");
					exit(0);
				}	
			}
		case 3 :
			exit(0);
			break; 
	}

}

