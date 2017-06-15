
//#pragma once
#ifndef _STORE_H
#define _STORE_H
#include "queue.h"

typedef struct{
	LinkQueue p1;   //һ����2����λ
	LinkQueue p2;   //������2����λ
	LinkQueue p3;   //������3����λ	
	int totalTime;   //��ʱ��
	double Money[3];   //�ֱ��Ӧ����������ʦ������
	double totalMoney;  //������480�����ڵ�������  
}Store;  


void InitStore(Store &s);    //��ʼ������
void DestroyStore(Store &s); //����
void ClearStore(Store &s);   //���
void goToStore(Store &s,Customer c);   //�˿ͽ�������  
bool beforeNextOne(Store &s,Customer c);		//����һ���˿ͽ���֮ǰ������ʱ��  
void goOutStore(Store &s,LinkQueue &p,int type);			//�������Ĺ˿��뿪����    
void calcMoney(Store &s,Customer c);    //������ʱ����������ȡ����
double getTotalMoney(Store &s);      //��ȡ�����Ӫҵ��
double getMoneyOfFirst(Store &s);    //��ȡһ�����ҵ�����
double getMoneyOfSecond(Store &s);    //��ȡ�������ҵ�����
double getMoneyOfThird(Store &s);    //��ȡ�������ҵ�����


#endif

