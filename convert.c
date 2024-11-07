/* Shadi El-Fares
 * Nov. 7, 2024
 * This program converts a number to  a base specified between 2 and 36
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "convert.h"
#include "parser.h"
#include "usage.h"

void convert_to_base(long number, int base) {

	if (number >= base) {
		convert_to_base(number / base, base);
	} else if (number < 0){
		putchar('-');
		if (abs(number) >= base){
			convert_to_base(abs(number) / base, base);
		}
	}

	int digit = abs(number) % base;
	if (digit < 10) {
		// '0' + 3 gives '3' for example
		putchar('0' + digit);  
	} else {
		// 'A' + 0 gives 'A', 'A' + 1 gives 'B', etc.
		putchar('A' + (digit - 10));  
	}

}

// Print the usage message
void print_usage() {
	fprintf(stderr, "Usage: convert [-b BASE] [-r START FINISH]\n");
	fprintf(stderr, "\t 1 < BASE < 37\n\t START and FINISH are long integers\n");
}

// Handle standard input or file input
void handle_input(int base) {
	while (true){
		long numb;
		int result = scanf("%ld", &numb);
		if (result == EOF) {
			break;
		} else if (result > 0){
			// Proceed with conversion if the input is not EOF
			convert_to_base(numb, base); 
			puts("");
		} else {
			fprintf(stderr, "Error: Non-long-int token encountered.\n");
			break;
		}
	} 
}

void range_processing(long start, long finish, int base){
	// If a range is provided, process the range of numbers
	for (long i = start; i <= finish; i++) {
		convert_to_base(i, base);
		printf("\n");
	}
}

int main(int argc, char *argv[]) {
	int base;
	long start = 0, finish = 0;
	int range_flag;

	// Parse command-line arguments
	if (parse_arguments(argc, argv, &base, &start, &finish, &range_flag) == 1) {
		return 1;
	}
	// Handle the input based on whether a range is provided or not
	if (range_flag) {
		range_processing(start, finish, base);
	}
	else {
		// Handle standard input conversion
		handle_input(base);
	}
	return 0;
}
