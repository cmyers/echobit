/*
Author: CMyers
Description:

Written as a learning exercise in C++, this is a simple demo to test passing ASCII from a terminal interface over serial to the BBC Microbit and displaying the character on the LED matrix.
The program is also responsible for outputting the character to the terminal.

Uses the Microbit runtime libary and specified toolchain: https://lancaster-university.github.io/microbit-docs/
*/

#include "MicroBit.h"
#include <stdio.h>
#include <string.h>

MicroBit uBit;

void doWork(int *counter);

int main(void)
{
	// Initialise the micro:bit runtime.
	uBit.init();

	int c;
	int *ptr_c;

	ptr_c = &c;

	*ptr_c = getchar();
	while(*ptr_c != EOF)
	{
		putchar(*ptr_c);
		uBit.display.print((char)*ptr_c);
		*ptr_c = getchar();
	}
	
	/*
	int a;
	char string [20];
	char input [20];
	int *ptr_to_a;
	ptr_to_a = &a;
	a = 0;

	scanf("%s", input);
	sprintf(string, input);
	strcat(string, "%d\n");

	while(1)
	{		
		doWork(ptr_to_a);
		printf(string, *ptr_to_a);
		uBit.display.scroll(input);
	}
	*/
	
	release_fiber();
}

void doWork(int *counter)
{
	*counter += 1;
	//uBit.sleep(1000);
}


