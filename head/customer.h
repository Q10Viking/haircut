//#pragma once
#ifndef _CUSTOMER_H
#define _CUSTOMER_H
#include <stdlib.h>

typedef struct{
	int durtime;       //��ʱ��
	int intertime;		//��һ���˿͵�����ʱ��
	int select;			//ѡ��������
	int remainTime;    //ʣ��ʱ��
}Customer;

void InitCustomer(Customer &C);

#endif