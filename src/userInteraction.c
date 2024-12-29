#include "../include/whoDroppedTheDB.h"

void displayMenu() {
	size_t choice;

	while(1) {
        	printf("\n--- PACIFIC STANDARD ---\n");
		printf(" -- CUSTOMER -- \n");
		printf("1. Register a New Customer \n");
        	printf("\n -- ACCOUNT -- \n");
		printf("2. Open a New Account\n");
		printf("3. Exiting");
        	printf("\nEnter your choice: ");
        	scanf("%zu", &choice);

        	switch (choice) {
                	case 1: {
                        	printf("Soon...");
				//TODO
				break;
                        	}

			case 2: {
				printf("Soon...");
				break;
				}

                	case 3: {
				printf("Exiting...");
                        	exit(0);
                        	}

                	default:
                        	printf("Please try again\n");
				break;
                        	}
	}
}
