/**
 * Author: Juan Carlo Mangaliag
 * Section: CMSC 128 AB-2L
 * Assign 001: Programming a Number Library
 * Date: February 13, 2016
 */

#include "assign001.h"

main () {	// contains the whole program
	int menuChoice = 5;
	
	while (showMenu(&menuChoice) != 0) {	// always shows the main menu, will only end the loop at choice = 0

		switch (menuChoice) {	// executes the user choice in main menu
			case 1: numToWords();	// converts the number in its equivalent word form
				break;
			case 2: wordsToNum();	// converts the equivalent word form of the number to number
				break;
			case 3: wordsToCurrency();	// converts the word form of number to number and adds the currency label at the start
				break;
			case 4: numberDelimited();	// accepts a number and moves the delimiter by a specific number from right to left
				break;
		}	
	} 
}