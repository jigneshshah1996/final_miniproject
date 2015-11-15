/* Contains all the header files, macros , functions and structure declarations */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include<termios.h>

#define NUM 999999999	


void viewshows();
void mainmenu();
void  mapshow(int *, int, int, int);
void savecustomer();
void dispcustomer();
void showtiming();
void seatdisp(int, int);
void admin();
void print_ticket();
void confirmation();
void checkout();
void resetbookings();
void galaxy();
void congrats();
void nosmoking();
void nosmoking1();
void userid_password();



int cust;

struct sh{
	int booking_id;
	char movie[16]; 
	char timing[16];
	int seatno[8];
};

struct customer{
	char username[16];
	char password[16];
	struct sh show;
	float tax;
	float rate;
	float amount;
        int seats;
        char name[32];
	char telno[16];
	char payment[16];
}c;



