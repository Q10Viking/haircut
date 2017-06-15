//#pragma once
#ifndef _QUEUE_H
#define _QUEUE_H
#include "customer.h"

/*定义数据类型*/
typedef Customer ElemType;

/*建立链表数据结构*/
typedef struct QNode 
{
	ElemType data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

/*异常处理*/
void Error(char *s);  
/*初始化节点*/
void InitQueue_L(LinkQueue &Q);
/*销毁链表*/
void DestroyList_L(LinkQueue &Q);
/*求表长*/
int ListLength_L(LinkQueue &Q);
/*入队操作*/
void EnQueue_L(LinkQueue &Q,ElemType e);
/*判断是否为空*/
int Empty_L(LinkQueue &Q);  
/*出队操作*/
void DeQueue_L(LinkQueue &Q,QNode *q);
/**删除操作**/  
void QueueDelete(LinkQueue &Q,int type,ElemType &c);


#endif