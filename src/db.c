#include "../include/whoDroppedTheDB.h"

CustomerDB *startDB() {
	printf("Initializing DB\n");

	CustomerDB *db = (CustomerDB *)malloc(sizeof(CustomerDB));
	if (!db) {
		printf("Failed to allocate memory\n");
		exit(1);
		 }

	db->customers = NULL;
	db->customerCount = 0;
	printf("DB Initialized: customers=%p, customerCount=%zu\n", db->customers, db->customerCount);
	return db;
}

void freeDB(CustomerDB *db) {
	if (!db) {
		printf("No DB !\n");
		return;
	}

		free(db->customers);
		db->customers = NULL;

	free(db);
	printf("/!\\ Database has been dropped by the intern /!\\\n");
}


void saveDB(CustomerDB *db, char *filename) {
	FILE *file = fopen(filename, "wb");
	if (!file) {
		printf("Unable to open file");
		return;
	}

	fwrite(&db->customerCount, sizeof(size_t), 1, file);

	for (size_t i = 0; i < db->customerCount; i++) {
		fwrite(&db->customers[i], sizeof(Customer), 1, file);
	}

	fclose(file);
	printf("Database saved to '%s'\n", filename);
}

CustomerDB  *loadDB(char *filename) {
	FILE *file = fopen(filename, "rb");

	// Create a new DB if no DB already
	if (!file) {
		printf("No previous DB...\n");
		return startDB();
	}

	// Try to allocate memory for the DB
	CustomerDB *db = (CustomerDB *)malloc(sizeof(CustomerDB));
    	if (!db) {
        	printf("Memory allocation failed while loading database.\n");
        	fclose(file);
        	exit(1);
    	}

	// Read the number of customers
	fread(&db->customerCount, sizeof(size_t), 1, file);

	// Allocate memory for customers
	db->customers = (Customer *)malloc(db->customerCount * sizeof(Customer));
	if (!db->customers) {
		printf("Failed to allocate memory for customers !\n");
		fclose(file);
		exit(1);
	}

	// Read all customers
	fread(db->customers, sizeof(Customer), db->customerCount, file);

	fclose(file);
	printf("Senior has restored the DB\n");
	return db;
}

void dropDbFile(char *filename) {
	if(remove(filename) == 0)
		printf("DB file has been targeted by the intern\n");
	else
		printf("Error deleting file\n");
}
















