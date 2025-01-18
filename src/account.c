#include "../include/whoDroppedTheDB.h"

void dbErrorCheck(CustomerDB *db) {
	// Check if db or customers available
	if (!db || db->customerCount == 0) {
                printf("No customer available\n");
                return;
	 }
}

void openAccount(CustomerDB *db) {
	//dbErrorCheck(db);
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

void viewCustomerAccounts(CustomerDB *db) {
	// Display user list
	viewCustomers(db);

	size_t customerID;
    	printf("Enter the Customer ID : ");
    	scanf("%zu", &customerID);

	// Check if the customer exists
    	Customer *customer = NULL;
    	for (size_t i = 0; i < db->customerCount; i++) {
        	if (db->customers[i].customerID == customerID) {
            		customer = &db->customers[i];
            		break;
       		 }
    	}


	if (!customer) {
        	printf("Customer not found\n");
        	return;
    	}

	// Display Accounts
	printf("\n--- Accounts for %s %s (Customer ID: %zu) ---\n",customer->name, customer->surname, customerID);
    	bool hasAccounts = false;
    	for (size_t i = 0; i < db->accountCount; i++) {
        	if (db->accounts[i].customerID == customerID) {
            	hasAccounts = true;
            	printf("Account Number: %zu\n", db->accounts[i].accountNumber);
            	printf("Account Type: %s\n", db->accounts[i].accountType);
            	printf("Balance: %.2f\n", db->accounts[i].balance);
            	printf("----------------------------\n");
        	}
    	}

	if (!hasAccounts) {
        	printf("No accounts found for this customer.\n");
    	}
}











