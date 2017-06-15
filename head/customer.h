//#pragma once
#ifndef _CUSTOMER_H
#define _CUSTOMER_H
#include <stdlib.h>

typedef struct{
	int durtime;       //理发时间
	int intertime;		//下一个顾客到来的时间
	int select;			//选择理发级别
	int remainTime;    //剩余时间
}Customer;

void InitCustomer(Customer &C);

#endif