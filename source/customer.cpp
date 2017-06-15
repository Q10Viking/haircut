#include "customer.h"  

void InitCustomer(Customer &C){
	//srand((unsigned)time(NULL));
	int R=rand();
	C.durtime=15+R%50;
	C.intertime=2+R%10;
	C.select=1+R%3;
	C.remainTime=C.durtime;
}
