//#pragma once
#ifndef _QUEUE_H
#define _QUEUE_H
#include "customer.h"

/*������������*/
typedef Customer ElemType;

/*�����������ݽṹ*/
typedef struct QNode 
{
	ElemType data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

/*�쳣����*/
void Error(char *s);  
/*��ʼ���ڵ�*/
void InitQueue_L(LinkQueue &Q);
/*��������*/
void DestroyList_L(LinkQueue &Q);
/*���*/
int ListLength_L(LinkQueue &Q);
/*��Ӳ���*/
void EnQueue_L(LinkQueue &Q,ElemType e);
/*�ж��Ƿ�Ϊ��*/
int Empty_L(LinkQueue &Q);  
/*���Ӳ���*/
void DeQueue_L(LinkQueue &Q,QNode *q);
/**ɾ������**/  
void QueueDelete(LinkQueue &Q,int type,ElemType &c);


#endif