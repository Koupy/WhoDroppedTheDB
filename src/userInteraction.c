#include "../include/whoDroppedTheDB.h"

void displayMenu() {
	size_t choice;

	printf("\n--- WhoDropTheDB ---\n");
	printf("1. Begin\n");
	printf("2. Quit\n");
	printf("Enter your choice: ");
	scanf("%zu", &choice);

        switch (choice) {
        	case 1:   {
			printf("Hello World !\n");
           		  }

		case 2:   {
			exit(0);
			  }

		default:
			printf("Please try again\n");
			}
}
