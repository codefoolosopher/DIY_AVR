#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdio.h>
#include "UART0.h"

#define UBRR_9600_1X 103
//#define UBRR_9600_2x 207

// instances of input and output for printf/scanf
FILE OUTPUT = FDEV_SETUP_STREAM(TX0_ch, NULL, _FDEV_SETUP_WRITE);
FILE INPUT = FDEV_SETUP_STREAM(NULL, RX0_ch, _FDEV_SETUP_READ);

int main(void)
{
	unit8_t counter = 100;
	char buf[20] = ""; // receive buffer

	stdout = &OUTPUT;
	stdin = &INPUT;

	UART0_INIT(UBRR_9600_1X);

	printf("\n");
	printf("Current Counter Value: ");
	printf("%d\r\n", counter);

	while (1)
	{
		scanf("%s", buf); // get input using scanf()

		if (strcasecmp(buf, "DOWN") == 0) // use strcasecmp instead
		{
			counter--;
			printf("Current Counter Value : ");
			printf("%d\r\n", counter);
		}
		else if (strcasecmp(buf, "UP") == 0)
		{
			counter++;
			printf("Current Counter Value : ");
			printf("%d\r\n", counter);
		}
		else // exception handling
		{
			printf("Invalid Command!! \r\n");
		}
	}
	return 0;
}

