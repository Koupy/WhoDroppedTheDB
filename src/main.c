#include "../include/whoDroppedTheDB.h"

int main(int argc,char **argv){
	CustomerDB *db = startDB();
	displayMenu();
	return 0;

}
