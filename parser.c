/* Shadi El-Fares 
 * This file parses the input for working input and returns 1 if anything is wrong, along with a usage message to stderr.
 * Nov 7, 2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "usage.h"

//Global Substitutions
#define MIN_BASE 2
#define MAX_BASE 36

int parse_arguments(int argc, char *argv[], int *base, long *start, long *finish, int *range_flag) {
	//Hard-coded 16 as its only used once and is a constant
	*base = 16;
	*range_flag = 0;

	for (int i = 1; i < argc; i++) {
		//Basicall if i+1 >= argc, then there is more inputted than the arguements provided.
		//This is error case as argc -1 = argv, so anything more than argc is outside of bounds for arguement vector
		if (strcmp(argv[i], "-b") == 0) {
			if (i + 1 >= argc) {
				print_usage();
				return 1;
			}
			//Change base if valid
			*base = atoi(argv[++i]);
			//Check if between acceptable values
			if (*base < MIN_BASE || *base > MAX_BASE) {
				print_usage();
				return 1;
			}
			//Check if we have more than the acceptable amount of arguements
			//Reduces possibility of going out of bounds.
		} else if (strcmp(argv[i], "-r") == 0) {
			if (i + 2 >= argc) {
				print_usage();
				return 1;
			}

			*start = atol(argv[++i]);
			*finish = atol(argv[++i]);
			*range_flag = 1;
		} else {
			print_usage();
			return 1;
		}
	}
	return 0;
}
