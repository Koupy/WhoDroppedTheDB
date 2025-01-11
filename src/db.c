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

	printf("Freeing DB...\n");

	if (db->customers) {
		for(size_t i = 0; i < db->customerCount; i++) {
			printf("Freeing customer %zu\n ...", i);
		}

		free(db->customers);
		db->customers = NULL;
		printf("All customers freed !\n");
	}

	free(db);
	db = NULL;
	printf("/!\\ Database has been dropped by the intern /!\\\n");
}



