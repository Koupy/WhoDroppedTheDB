#include "../include/whoDroppedTheDB.h"

void registerCustomer(CustomerDB *db) {
	if (!db) {
		printf("No DB\n");
		return;
	}

	char firstName[50];
	char lastName[50];

	printf("\n*** Registering a New Customer ***\n");
    	printf("Enter First Name: ");
    	scanf("%s", firstName);
	printf("Enter Last Name: ");
    	scanf("%s", lastName);

	db->customers = (Customer *)realloc(db->customers, (db->customerCount + 1) * sizeof(Customer));
	if (!db->customers) {
		printf("Failed");
		exit(1);
	}

	Customer *newCustomer = &db->customers[db->customerCount];
	newCustomer->customerID = db->customerCount + 1;
	strncpy(newCustomer->name, firstName, sizeof(newCustomer->name) - 1);
    	strncpy(newCustomer->surname, lastName, sizeof(newCustomer->surname) - 1);

	db->customerCount++;
	printf("Registering ...\n");
	printf("Success ! %s %s has been added !\n", lastName, firstName);
}

void viewCustomers(CustomerDB *db) {
	if (!db || db->customerCount == 0) {
		printf("No Customers in the DB\n");
		return;
	}

	printf("*** Registered Customers ***\n");

	for (size_t i = 0; i < db->customerCount; i++) {
		Customer *customer = &db->customers[i];
		printf("- %s %s (ID : %zu)\n", customer->surname, customer->name, customer->customerID);
		printf("     ----     \n");
	}
}


void selectCustomer(CustomerDB *db) {
	if (!db || db->customerCount == 0) {
		printf("No Customers in the DB\n");
		return;
	}

	viewCustomers(db);

	size_t customerID;
	printf("Enter a customer ID : \n");
	scanf("%zu", &customerID);

	for (size_t i = 0; i < db->customerCount; i++) {
		if (db->customers[i].customerID == customerID) {
                	printf("- %s %s (ID : %zu)\n", db->customers[i].surname, db->customers[i].name, db->customers[i].customerID);
			printf("Soon you will see customer bank account\n");
			return;
		}
	}
	printf("No customers with ID %zu\n", customerID);
}












