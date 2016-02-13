#include <stdio.h>
#include <string.h>

int showMenu(int *menuChoice) {	// shows the Main Menu Screen and asks for user choice
	printf("\n==========================\n");
	printf("\tMain Menu\n");
	printf("==========================\n");
	printf("[1] numToWords\n");
	printf("[2] wordsToNum\n");
	printf("[3] wordsToCurrency\n");
	printf("[4] numberDelimited\n");
	printf("[0] Exit\n");
	printf("--------------------------\n");
	printf("Choice: ");
	scanf("%d", menuChoice);

	return *menuChoice;
}


char *oneDigitDeterminer(int digitPlace, int wholeNumberLength, char wholeNumber[]) {

	switch(wholeNumber[wholeNumberLength-digitPlace]) {
		case '0':
			return "zero";
		case '1':
			return "one";
		case '2':
			return "two";
		case '3':
			return "three";
		case '4':
			return "four";
		case '5':
			return "five";
		case '6':
			return "six";
		case '7':
			return "seven";
		case '8':
			return "eight";
		case '9':
			return "nine";
	}
}


char *tensDigitDeterminer(int digitPlace, int wholeNumberLength, char wholeNumber[]) { 

	switch(wholeNumber[wholeNumberLength-digitPlace]) {
		case '0':
			return "ten";
		case '1':
			return "eleven";
		case '2':
			return "twelve";
		case '3':
			return "thirteen";
		case '4':
			return "fourteen";
		case '5':
			return "fifteen";
		case '6':
			return "sixteen";
		case '7':
			return "seventeen";
		case '8':
			return "eighteen";
		case '9':
			return "nineteen";
	}
}


char *twoDigitDeterminer(int digitPlace, int wholeNumberLength, char wholeNumber[], int *oneInTens) {

	switch(wholeNumber[wholeNumberLength-digitPlace]) {
		case '0':
			return "zero";
		case '1':
			*oneInTens = 1;
			return tensDigitDeterminer(digitPlace-1, wholeNumberLength, wholeNumber);
		case '2':
			return "twenty";
		case '3':
			return "thirty";
		case '4':
			return "fourty";
		case '5':
			return "fifty";
		case '6':
			return "sixty";
		case '7':
			return "seventy";
		case '8':
			return "eighty";
		case '9':
			return "ninety";
	}
}


void numToWords() {
	char wholeNumber[7], digitName[5], hundredThousand[5], tenThousand[5], thousand[5];
	int wholeNumberLength, oneInTens = 0;

	printf("\n==========================\n");
	printf("\n\tnumToWords\n");
	printf("==========================\n");
	printf("Enter a whole number: ");
	scanf("%s", wholeNumber);
	printf("\nConverted: ");

	wholeNumberLength = strlen(wholeNumber);
	
	switch(wholeNumberLength) {
		case 7: if (strcmp(strcpy(digitName, oneDigitDeterminer(7, wholeNumberLength, wholeNumber)), "zero") != 0)
					printf("%s million ", digitName);
		case 6: if (strcmp(strcpy(hundredThousand, oneDigitDeterminer(6, wholeNumberLength, wholeNumber)), "zero") != 0)
					printf("%s hundred ", hundredThousand);
		case 5: if (strcmp(strcpy(tenThousand, twoDigitDeterminer(5, wholeNumberLength, wholeNumber, &oneInTens)), "zero") != 0)
					printf("%s ", tenThousand);
		case 4: if (oneInTens == 0){
					if (strcmp(strcpy(thousand, oneDigitDeterminer(4, wholeNumberLength, wholeNumber)), "zero") != 0)	
						printf("%s ", thousand);
				}
				oneInTens = 0;
				if (! (wholeNumberLength == 7 && strcmp(hundredThousand, "zero") == 0 && strcmp(tenThousand, "zero") == 0 && strcmp(thousand, "zero") == 0))
					printf("thousand ");

		case 3: if (strcmp(strcpy(digitName, oneDigitDeterminer(3, wholeNumberLength, wholeNumber)), "zero") != 0)
					printf("%s hundred ", digitName);
		case 2: if (strcmp(strcpy(digitName, twoDigitDeterminer(2, wholeNumberLength, wholeNumber, &oneInTens)), "zero") != 0)
					printf("%s ", digitName);
		case 1:	if (oneInTens == 0){
					if (strcmp(strcpy(digitName, oneDigitDeterminer(1, wholeNumberLength, wholeNumber)), "zero") != 0)
						printf("%s ", digitName);
				}
				oneInTens = 0;
				if ((wholeNumberLength) == 1 && strcmp(strcpy(digitName, oneDigitDeterminer(1, wholeNumberLength, wholeNumber)), "zero") == 0)
					printf("%s ", digitName);		
	}

}