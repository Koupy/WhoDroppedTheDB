#include "../include/whoDroppedTheDB.h"

CustomerDB *startDB() {
	printf("Initializing DB\n");

	CustomerDB *db = (CustomerDB *) malloc(sizeof(CustomerDB));
	if (!db) {
		printf("Fail");
		exit(1);
		 }

	db->customers = NULL;
	db->customerCount = 0;
	printf("Ok");
	return db;
}
