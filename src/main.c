#include "../include/whoDroppedTheDB.h"

int main(int argc,char **argv){
	char *filename = "pacificaStandard.dat";

	// Load a database if exist
	CustomerDB *db = loadDB(filename);

	// User payload
	displayMenu(db, filename);

	return 0;

}
