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
