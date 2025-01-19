#include "../include/whoDroppedTheDB.h"

// Add a new customer in the DB
void registerCustomer(CustomerDB *db) {
	// Check if a database is created
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

	// Resize the previous malloc function from startDB() to welcome then new customer 
	db->customers = (Customer *)realloc(db->customers, (db->customerCount + 1) * sizeof(Customer));
	if (!db->customers) {
		printf("Failed");
		exit(1);
	}

	// Copy data into the customer table
	Customer *newCustomer = &db->customers[db->customerCount];
	newCustomer->customerID = db->customerCount + 1;
	strncpy(newCustomer->name, firstName, sizeof(newCustomer->name) - 1);
    	strncpy(newCustomer->surname, lastName, sizeof(newCustomer->surname) - 1);

	db->customerCount++;
	printf("Registering ...\n");
	printf("Success ! %s %s has been added !\n", lastName, firstName);
}

// Display all the available customrs
void viewCustomers(CustomerDB *db) {
	// Check if one user minimum is available
	if (!db || db->customerCount == 0) {
		printf("No Customers in the DB\n");
		return;
	}

	printf("*** Registered Customers ***\n");

	// Display all found customers
	for (size_t i = 0; i < db->customerCount; i++) {
		Customer *customer = &db->customers[i];
		printf("- %s %s (ID : %zu)\n", customer->surname, customer->name, customer->customerID);
		printf("     ----     \n");
	}
}

// Displat only selected customers
void selectCustomer(CustomerDB *db) {
	// Check if one user minimum is available
	if (!db || db->customerCount == 0) {
		printf("No Customers in the DB\n");
		return;
	}

	// Display the customer list
	viewCustomers(db);

	size_t customerID;
	printf("Enter a customer ID : ");
	scanf("%zu", &customerID);

	// Display data of the current customer
	for (size_t i = 0; i < db->customerCount; i++) {
		if (db->customers[i].customerID == customerID) {
                	printf("- %s %s (ID : %zu)\n", db->customers[i].surname, db->customers[i].name, db->customers[i].customerID);
			selectCustomerMenu(db, i);
			return;
		}
	}
	printf("\nNo customers with ID %zu\n", customerID);
}

// Add action menu for user management
void selectCustomerMenu(CustomerDB *db, size_t customerIndex) {
	Customer *customer = &db->customers[customerIndex];
	size_t choice;

	while (1) {
		printf("\n\n *** Actions available ***\n");
		printf("1. Update Customer\n");
        	printf("2. Delete Customer\n");
		printf("3. Exit\n");
		printf("Your choice : ");
		scanf("%zu", &choice);

		switch (choice) {
			case 1 :
				updateCustomer(customer);
				return;

			case 2 :
				deleteCustomer(db, customerIndex);
				return;

			case 3 :
				// TODO
				printf("\nSoon you will see customer bank account\n");
				return;

			default :
				printf("\nPlease try again\n");
				break;
		}
	}
}

// Modifity the informations of a selected customer
void updateCustomer(Customer *customer){
	char firstName[50];
	char lastName[50];

	printf("\n*** Updating Customer ***\n");
	printf("Enter new First Name : ");
    	scanf(" %[^\n]", firstName);

	// Overwrite current data for the new ones ('\0' useful for avoiding string overwriting
	if (strlen(firstName) > 0) {
        strncpy(customer->name, firstName, sizeof(customer->name) - 1);
        customer->name[sizeof(customer->name) - 1] = '\0';
	}

	printf("\nEnter new Last Name : ");
    	scanf(" %[^\n]", lastName);

	if (strlen(lastName) > 0) {
        strncpy(customer->surname, lastName, sizeof(customer->surname) - 1);
        customer->surname[sizeof(customer->surname) - 1] = '\0';
    	}

	printf("\nCustomer updated !\n");
}

// Delete customer from the databse
void deleteCustomer(CustomerDB *db, size_t customerIndex) {
	// Check if number from the index existe
	if(!db || db->customerCount == 0 || customerIndex >= db->customerCount) {
		printf("Invalid index \n");
		return;
	}

	printf("\n*** Deleting Customer ***\n");
	printf("Customer has been deleted !\n");

	//Moving existing users in DB
	for (size_t i = customerIndex; i < db->customerCount - 1; i++) {
		db->customers[i] = db->customers[i + 1];
	}

	db->customerCount--;

	//Resizing thz array
	db->customers = (Customer *)realloc(db->customers, db->customerCount * sizeof(Customer));
	if (db->customerCount > 0 && !db->customers) {
		printf("Reallocation Failed\n");
		exit(1);
	}
}
