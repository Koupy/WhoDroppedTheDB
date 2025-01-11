#include "../include/whoDroppedTheDB.h"

int main(int argc,char **argv){
	CustomerDB *db = startDB();
	displayMenu(db);
	freeDB(db);
	return 0;

}
