#include "../include/whoDroppedTheDB.h"

// Display all the available actions to the user
void displayMenu(CustomerDB *db, char *filename) {
	size_t choice;

	while(1) {
        	printf("\n--- PACIFIC STANDARD ---\n");
		printf("\n -- CUSTOMER -- \n");
		printf("1. Register a New Customer \n");
		printf("2. View All customers\n");
		printf("3. Select a customer\n");
        	printf("\n -- ACCOUNT -- \n");
		printf("4. Open a New Account\n");
		printf("5. Select an account\n");
		printf("6. See all accounts\n");
		printf("\n -- OTHER --\n");
		printf("7. Drop the DB\n");
		printf("8. Exit\n");
        	printf("\nEnter your choice: ");
        	scanf("%zu", &choice);

        	switch (choice) {
                	case 1: {
				printf("\n");
				registerCustomer(db);
				break;
                        	}

			case 2: {
				printf("\n");
				viewCustomers(db);
				break;
				}

			case 3: {
				printf("\n");
				selectCustomer(db);
				break;
				}

			case 4: {
				printf("\n");
				openAccount(db);
				break;
				}

			case 5: {
				printf("\n");
				viewCustomerAccounts(db);
				break;
				}

			case 6 : {
				printf("\n");
				viewAllAccounts(db);
				break;
				}

			case 7: {
				printf("\n");
				dropDbFile(filename);
				freeDB(db);
				exit(0);
				}

			 case 8: {
                                printf("\n");
                                saveDB(db, filename);
                                freeDB(db);
                                exit(0);
                                }

                	default:
                        	printf("\nPlease try again\n");
				break;
                        	}
	}
}
