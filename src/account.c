#include "../include/whoDroppedTheDB.h"

void openAccount(CustomerDB *db) {
	// Check if db or customers available
	if (!db || db->customerCount == 0) {
		printf("No customer available\n");
		return;
	}

	viewCustomers(db);

	size_t customerID;
	printf("Enter the customer ID : ");
	scanf("%zu", &customerID);

	//Check if customer exists
	Customer *linkedCustomer = NULL;
    	for (size_t i = 0; i < db->customerCount; i++) {
        	if (db->customers[i].customerID == customerID) {
            		linkedCustomer = &db->customers[i];
            		break;
        	}
    	}

	if (!linkedCustomer) {
		printf("Customer not found\n");
		return;
	}

	// Account creation
	char accountType[20];
	double initialBalance;

	printf("Enter account type : ");
    	scanf("%19s", accountType);

	printf("Enter initial balance: ");
    	scanf("%lf", &initialBalance);

	// DB allocation verification
	db->accounts = (Account *)realloc(db->accounts, (db->accountCount + 1) * sizeof(Account));
    	if (!db->accounts) {
        	printf("Error: Memory allocation failed while creating the account.\n");
        	return;
    	}

    	Account *newAccount = &db->accounts[db->accountCount];
    	newAccount->accountNumber = db->accountCount + 1; // Generate a unique account number
    	newAccount->customerID = customerID;
    	newAccount->balance = initialBalance;
    	strncpy(newAccount->accountType, accountType, sizeof(newAccount->accountType) - 1);
    	newAccount->accountType[sizeof(newAccount->accountType) - 1] = '\0'; // \0 stand for string verification

    	db->accountCount++;

    	printf("Account created ! Account Number: %zu\n", newAccount->accountNumber);
}



















