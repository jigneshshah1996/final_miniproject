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

/* Remaining 3 functions are ASCII daigrams shown during execution of the program */
/* Some ASCII test is present in all of the files and the whole file is printed in the screen usiing getc() till EOF */
void galaxy(){
	FILE *GALAXY;
	GALAXY = fopen("galaxy.txt", "r");
	int gal;
	while ((gal = getc(GALAXY)) != EOF)
        putchar(gal);
	fclose(GALAXY);	

}

void congrats(){
	FILE *CONGATS;
	CONGATS = fopen("congats.txt", "r");
	int gal;
	while ((gal = getc(CONGATS)) != EOF)
        putchar(gal);
	fclose(CONGATS);
	sleep(2);	
}
void nosmoking() {
	FILE *SMOKING;
	SMOKING = fopen("smoking1.txt", "r");
	int gal;
	while ((gal = getc(SMOKING)) != EOF)
        putchar(gal);
	fclose(SMOKING);
	sleep(1);	
}
void nosmoking1() {
	system("clear");
	FILE *SMOKING;
	SMOKING = fopen("smoking.txt", "r");
	int gal;
	while ((gal = getc(SMOKING)) != EOF)
        putchar(gal);
	fclose(SMOKING);
	sleep(1);	
}
