
//#pragma once
#ifndef _STORE_H
#define _STORE_H
#include "queue.h"

typedef struct{
	LinkQueue p1;   //一级，2个座位
	LinkQueue p2;   //二级，2个座位
	LinkQueue p3;   //三级，3个座位	
	int totalTime;   //总时间
	double Money[3];   //分别对应三个级别理发师的收入
	double totalMoney;  //理发店在480分钟内的总收入  
}Store;  


void InitStore(Store &s);    //初始化理发店
void DestroyStore(Store &s); //销毁
void ClearStore(Store &s);   //清空
void goToStore(Store &s,Customer c);   //顾客进入理发店  
bool beforeNextOne(Store &s,Customer c);		//在下一个顾客进店之前处理，理发时间  
void goOutStore(Store &s,LinkQueue &p,int type);			//理发结束的顾客离开理发店    
void calcMoney(Store &s,Customer c);    //计算理发时间后，理发店的收取费用
double getTotalMoney(Store &s);      //获取理发店的营业额
double getMoneyOfFirst(Store &s);    //获取一级理发室的收入
double getMoneyOfSecond(Store &s);    //获取二级理发室的收入
double getMoneyOfThird(Store &s);    //获取三级理发室的收入


#endif

