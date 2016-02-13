#include "assign001.h"

main () {
	int menuChoice = 5;
	
	while (showMenu(&menuChoice) != 0) {

		switch (menuChoice) {
			case 1: numToWords();
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
		}	
	} 
}