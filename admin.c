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



/* Admin access functions 
   Display bookings of all the customers 
   Reset all bokings
  REMEMBER : PASSWORD for admin : 'password'  */

#include "bookings.h"
/* Shows the ADMIN options */
void admin() {
	int adminopt;
	printf("\n\t\t1. View Customer Bookings : \n\n");
	printf("\t\t2. Reset all Bookings\t");
	scanf("%d", &adminopt);
	if(adminopt == 1) {
		/* show the bookings one by one to the ADMIN */
		/* PASSWORD = 'password' */
		dispcustomer();
	}
	else if (adminopt == 2) {
		resetbookings();
	}
	else {
		printf("\t\tWrong Input ");
	}
}
/* Only For ADMIN */

/* Display each customer booking one by one */
void dispcustomer() {
	system("clear");
	/* show each booking one by one by reading from the file */
	printf("\n\t******************* Customer Details.. *******************\n\n\n");
	FILE *PBOOKS;
	PBOOKS = fopen("book1.txt", "r+");
	rewind(PBOOKS);        /* go to start of file     */
	int c;
	printf("\n\nHere is the list of your bookings:\n\n");
	if (PBOOKS == NULL) {
	printf ("\n\t*****No Bookings Yet********\n\n\n");
	}
	while ((c = getc(PBOOKS)) != EOF)
        putchar(c);
	fclose(PBOOKS);	
	printf("\n\tThank You\n\n ");
	exit(0);
}


/* Delete all bookings for a fresh start for the next day */
void resetbookings(){
	/* Remove Customer Bookings */
	remove("book1.txt");
	/* Remove shows and their Seat No.s */
	remove("M1_T1.txt");
	remove("M1_T2.txt");
	remove("M1_T3.txt");
	remove("M2_T1.txt");
	remove("M2_T2.txt");
	remove("M2_T3.txt");
	remove("M3_T1.txt");
	remove("M3_T2.txt");
	printf("\n\nAll BOOKINGS Reseted \n\n");
	exit(0);
}
