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



#include "bookings.h"

/* This file takes the remaining information from thet user like name telephone number and saves it in the struct customer */
/* Printing the final ticket is done by the function print_ticket */



/* Saving the details of the customer in a file book1.txt*/
/* using rand() funtion for generating a random booking id */
void savecustomer() {
  	FILE *PBOOKS;
	int choice;
	PBOOKS = fopen("book1.txt", "a+");
	printf("\n\n\tEnter YOUR Name : ");
	scanf("%s", c.name);

        printf("\n\tEnter Customer Contact Number[10] : ");
	scanf("%s", c.telno);
	printf("\n\n\n\tAmount to be payed : %0.2f\n\n", c.amount);
     
	while(1) {
	printf("\tEnter Type Of Payment : \n"
		"\n\t\t[1] : Credit/Debit Card\t\n"
		"\n\t\t[2] : Internet Banking\t"); 
		scanf("%d", &choice);
		if(choice == 1) {
			strcpy(c.payment,"Credit/Debit Card");
			break; 
		}
		else if(choice == 2) {
			strcpy(c.payment,"Internet Banking");
			break;
		}
		else
		printf("Failed: Wrong Input\n");	
	}		

	/* Getting a random BOOKING ID */
	int m;
	srand (time(NULL));
	m = rand() % 30 + 1985;
	c.show.booking_id = m;		

	/* ----------- saving customer details -----------*/	
	/* pass the customer details into the file */
	fprintf(PBOOKS, "Username: %s \t Password:%s\n", c.username, c.password );
	fprintf(PBOOKS, "BOOKING ID : %d\n", c.show.booking_id );
	fprintf(PBOOKS, "Booked for %s  @  %s\nNo. of seats Booked : %d\n", c.show.movie, c.show.timing, c.seats);
	fprintf(PBOOKS, "Seat No.s : ");
	int arr;
	for(arr = 0; arr < cust; arr++)
	fprintf(PBOOKS, "-%d- ", c.show.seatno[arr]);
	fprintf(PBOOKS, "\nAmount : %f", c.amount);
	fprintf(PBOOKS, "\nName : %s\nTelephone no : %s\nType Of Payment : %s\n\n\n", c.name, c.telno, c.payment);	
	fclose(PBOOKS);
	printf("\n\n\n\t\t\t\t\t\t Thank You ...\n\n");   	
	printf("\n\t\t\t\t\t\tYour Booking Process Is Done..\n");
	//sleep(5);
	//system("clear");
	congrats();
	
	/* Printing the Ticket on the screen */
	print_ticket();
	system("clear");
	nosmoking();
	nosmoking1();
	/* Returning to main menu */
	mainmenu(); 
}
 
/* Printing the final ticket with details of your day, time of show, booking id, total cost including tax and our seat numbers */
void print_ticket() {
 	system("clear");
 	time_t now = time(NULL);
  	struct tm *t = localtime(&now);
 	char p[10];
 	/* Getting the systems date from the system */
	sprintf(p,"%d/%d/%d",t->tm_mday,t->tm_mon +1, t->tm_year +1900);
 	printf("\n\n\t\t\t\t\t************************TICKET********************\n\n ");
 	printf( "\t\t\t\t\t\t    TICKET SUMMARY\n\n\n "
	"\t\t\t\t\t\tVenue: (Galaxy Cinemas - Pune) \n"
	"\t\t\t\t\t\tDate: %s \n\n", p);
 	printf("\t\t\t\t\t\t%s  @  %s\n", c.show.movie, c.show.timing);
	printf("\t\t\t\t\t\tTotal Seats: %d\n", c.seats);
	int arr;
	printf("\t\t\t\t\t\tSeat Info : ");
	int hello;
	for(arr = 0; arr < cust; arr++)
	printf("-%d- ", c.show.seatno[arr]);
	printf("\n\n\t\t\t\t\t\tTicket(s) : %0.2f\n", c.rate);
	printf("\nt\t\t\t\t\t\tInternet + Handling Fees : %0.2f\n", c.tax  );
	printf("\n\t\t\t\t\t\tGRAND TOTAL : %0.2f\n\n", c.amount);
	printf("\n\n\t\t\t\t\t************************TICKET********************\n\n ");
	printf("\n\n\t\tEnter 0 to return to MAIN MENU : ");
	scanf("%d", &hello);
	if(hello == 0) {
 		return;
 	}
}

