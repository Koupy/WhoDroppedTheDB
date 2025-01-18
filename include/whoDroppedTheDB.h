#ifndef WHO_DROPPED_THE_DB_H
#define WHO_DROPPED_THE_DB_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Customer structure
typedef struct {
	size_t customerID;
	char name[50];
	char surname[50];
           	} Customer;

// Account structure
typedef struct {
	size_t accountNumber;
	size_t customerID;
	double balance;
	char accountType[20];
		} Account;

// Customer accounts structure
typedef struct {
	Customer *customers;
	size_t customerCount;
	Account *accounts;
	size_t accountCount;
		} CustomerDB;

// Menu Functions
void displayMenu(CustomerDB *db);

// Database Functions
CustomerDB *startDB();
void freeDB(CustomerDB *db);
void saveDB(CustomerDB *db, char *filename);
void deleteDbFile(char * filename);
CustomerDB *loadDB(char *filename);

// Database Customer Interaction
void registerCustomer(CustomerDB *db);
void viewCustomers(CustomerDB *db);
void selectCustomer(CustomerDB *db);
void selectCustomerMenu(CustomerDB *db, size_t customerIndex);
void updateCustomer(Customer *customer);
void deleteCustomer(CustomerDB *db, size_t customerIndex);

// Account Functions
void dbErrorCheck(CustomerDB *db);
void openAccount(CustomerDB *db);
void viewCustomerAccounts(CustomerDB *db);

#endif
