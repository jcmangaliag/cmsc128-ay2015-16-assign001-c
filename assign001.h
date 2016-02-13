#include <stdio.h>
#include <string.h>
/*
typedef struct numInWord {
	char wordList[50];
} wordNumList;
*/
int showMenu(int *menuChoice) {	
// shows the Main Menu Screen and asks for user choice

	printf("\n\n==========================\n");
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
// returns the word form of a selected one digit

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
// returns the word form of a selected number from 10-19

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


char *secondDigitDeterminer(int digitPlace, int wholeNumberLength, char wholeNumber[], int *oneInTens) { 
// returns the word form of a selected tens or ten thousands digit from 10-90

	switch(wholeNumber[wholeNumberLength-digitPlace]) {
		case '0':
			return "zero";
		case '1':
			*oneInTens = 1;
			return tensDigitDeterminer(digitPlace-1, wholeNumberLength, wholeNumber);	
			// determines the word form of tens and ones of numbers (10-19)
		case '2':
			return "twenty";
		case '3':
			return "thirty";
		case '4':
			return "forty";
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


void numToWords() {	// asks for a whole number and prints its word form
	char wholeNumber[7], digitName[5], hundredThousand[5], tenThousand[5], thousand[5];
	int wholeNumberLength, oneInTens = 0;

	printf("\n==========================\n");
	printf("\tnumToWords\n");
	printf("==========================\n");
	printf("Enter a whole number: ");
	scanf("%s", wholeNumber);	// treats the number as a string
	printf("\nConverted: ");

	wholeNumberLength = strlen(wholeNumber);	// determines the string length of the whole number
	
	switch(wholeNumberLength) {	// checks each digit in the string (from millions to ones) and prints the correct word form
		case 7: if (strcmp(strcpy(digitName, oneDigitDeterminer(7, wholeNumberLength, wholeNumber)), "zero") != 0)
					printf("%s million ", digitName);	// determines the word form of millions digit and will only print if it is not zero
		case 6: if (strcmp(strcpy(hundredThousand, oneDigitDeterminer(6, wholeNumberLength, wholeNumber)), "zero") != 0)
					printf("%s hundred ", hundredThousand);	// prints hundred thousands digit
		case 5: if (strcmp(strcpy(tenThousand, secondDigitDeterminer(5, wholeNumberLength, wholeNumber, &oneInTens)), "zero") != 0)
					printf("%s ", tenThousand);	// prints the ten thousands digit
		case 4: if (oneInTens == 0){	// if the number does not fall between 10-19, it will print the thousands digit
					if (strcmp(strcpy(thousand, oneDigitDeterminer(4, wholeNumberLength, wholeNumber)), "zero") != 0)	
						printf("%s ", thousand);
				}
				oneInTens = 0;	// resets the checker of 10-19 to false/0
				if (! (wholeNumberLength == 7 && strcmp(hundredThousand, "zero") == 0 && strcmp(tenThousand, "zero") == 0 && strcmp(thousand, "zero") == 0))
					printf("thousand ");	// it will print thousand label if the number is less than a million and its hundred thousands, ten thousands
				// and thousands digit is not zero

		case 3: if (strcmp(strcpy(digitName, oneDigitDeterminer(3, wholeNumberLength, wholeNumber)), "zero") != 0)
					printf("%s hundred ", digitName);	// prints the hundreds digit
		case 2: if (strcmp(strcpy(digitName, secondDigitDeterminer(2, wholeNumberLength, wholeNumber, &oneInTens)), "zero") != 0)
					printf("%s ", digitName);	// prints the tens digit
		case 1:	if (oneInTens == 0){	// if the number does not fall between 10-19, it will print the ones digit
					if (strcmp(strcpy(digitName, oneDigitDeterminer(1, wholeNumberLength, wholeNumber)), "zero") != 0)
						printf("%s ", digitName);
				}
				oneInTens = 0;	// resets the checker of 10-19 to false/0
				if ((wholeNumberLength) == 1 && strcmp(strcpy(digitName, oneDigitDeterminer(1, wholeNumberLength, wholeNumber)), "zero") == 0)
					printf("%s ", digitName);	// prints zero if the number is 0
	}
}


int wordToDigitDeterminer(char *wordNumList) {	// returns the number form of the word version of number

	if (strcmp(wordNumList, "one") == 0)
		return 1;
	else if (strcmp(wordNumList, "two") == 0)
		return 2;
	else if (strcmp(wordNumList, "three") == 0)
		return 3;
	else if (strcmp(wordNumList, "four") == 0)
		return 4;
	else if (strcmp(wordNumList, "five") == 0)
		return 5;
	else if (strcmp(wordNumList, "six") == 0)
		return 6;
	else if (strcmp(wordNumList, "seven") == 0)
		return 7;
	else if (strcmp(wordNumList, "eight") == 0)
		return 8;
	else if (strcmp(wordNumList, "nine") == 0)
		return 9;
	else if (strcmp(wordNumList, "zero") == 0)
		return 0;

	else if (strcmp(wordNumList, "ten") == 0)
		return 10;
	else if (strcmp(wordNumList, "eleven") == 0)
		return 11;
	else if (strcmp(wordNumList, "twelve") == 0)
		return 12;
	else if (strcmp(wordNumList, "thirteen") == 0)
		return 13;
	else if (strcmp(wordNumList, "fourteen") == 0)
		return 14;
	else if (strcmp(wordNumList, "fifteen") == 0)
		return 15;
	else if (strcmp(wordNumList, "sixteen") == 0)
		return 16;
	else if (strcmp(wordNumList, "seventeen") == 0)
		return 17;
	else if (strcmp(wordNumList, "eighteen") == 0)
		return 18;
	else if (strcmp(wordNumList, "nineteen") == 0)
		return 19;

	else if (strcmp(wordNumList, "twenty") == 0)
		return 20;
	else if (strcmp(wordNumList, "thirty") == 0)
		return 30;
	else if (strcmp(wordNumList, "forty") == 0)
		return 40;
	else if (strcmp(wordNumList, "fifty") == 0)
		return 50;
	else if (strcmp(wordNumList, "sixty") == 0)
		return 60;
	else if (strcmp(wordNumList, "seventy") == 0)
		return 70;
	else if (strcmp(wordNumList, "eighty") == 0)
		return 80;
	else if (strcmp(wordNumList, "ninety") == 0)
		return 90;

	else {
		printf("\nIncorrect Input!\n");
		return 0;
	}
}


void wordsToNum() {	// asks for a word form of number and it prints the number

	char wordNumber[100], wordNumList[20][100];
	int i, j=0, k=0, wordQuantity, value=0, hundredthoupass = 0;

	printf("\n==========================\n");
	printf("\twordsToNum\n");
	printf("==========================\n");
	printf("Enter the number in words: ");
	getchar();
	fgets(wordNumber, 100, stdin);
	printf("\nConverted: ");

	for (i=0; i<strlen(wordNumber); i++) {
		
		if (wordNumber[i] != ' ') {
			wordNumList[j][k] = wordNumber[i];
			k++;
		} else {
			wordNumList[j][k] = '\0';
			j++;
			k = 0;
		}
	}
	wordNumList[j][k-1] = '\0';

	wordQuantity = j+1;

	for (i = wordQuantity-1; i>=0; i--) {
		if (strcmp(wordNumList[i], "million") == 0) {

			value = value + (1000000 * wordToDigitDeterminer(wordNumList[i-1]));
			i--;
		} else if (strcmp(wordNumList[i], "hundred") == 0) {

			if (hundredthoupass == 0) {
				value += (100 * wordToDigitDeterminer(wordNumList[i-1]));
			} else {	// if in hundred thousands place
				value += (100000 * wordToDigitDeterminer(wordNumList[i-1]));
			}
			i--;		
		} else if (strcmp(wordNumList[i], "thousand") == 0) {
			j=1;
			hundredthoupass = 1;
			while (i>j && strcmp(wordNumList[i-j], "million") != 0 && strcmp(wordNumList[i-j], "hundred") != 0) {
				j++;
			}

			if (j==1 && i==j){
				value += (1000 * wordToDigitDeterminer(wordNumList[i-j]));
				i--;
			} else if (j==2 && (i!=j)) {
				value += (1000 * wordToDigitDeterminer(wordNumList[i-(j-1)]));
				i--;
			}
			else if (j==2) {
				value += (1000 * (wordToDigitDeterminer(wordNumList[i-j]) + wordToDigitDeterminer(wordNumList[i-(j-1)])));
				i-=2;
			} else if (j>2) {
				value += (1000 * (wordToDigitDeterminer(wordNumList[i-(j-1)]) + wordToDigitDeterminer(wordNumList[i-(j-2)])));
				i-=2;
			}
		} else {
			value += wordToDigitDeterminer(wordNumList[i]);
		}
	}

	printf("%d", value);
}