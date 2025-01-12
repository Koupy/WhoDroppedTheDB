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

















