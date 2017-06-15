#include "common.h"
#include "queue.h"

/*�쳣����*/
void Error(char *s)
{cout<<s<<endl;}



/*��ʼ���ڵ�*/
void InitQueue_L(LinkQueue &Q){
	Q.front = Q.rear = new QNode;
	Q.front->next = NULL;
}
/*��������*/
void DestroyList_L(LinkQueue &Q){
	while(Q.front){
		Q.rear = Q.front->next;
		delete Q.front;
		Q.front = Q.rear;
	}
}
/*���*/
int ListLength_L(LinkQueue &Q)
{
	int length = 0;
	QNode *p = Q.front;
	while(p->next){
		length++;
		p = p->next;
	}
	return length;
}
/*��Ӳ���*/
void EnQueue_L(LinkQueue &Q,ElemType e)
{
	QNode *p = new QNode;
	p->data = e; 
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
}

/*�ж��Ƿ�Ϊ��*/
int Empty_L(LinkQueue &Q){
	if(Q.front->next == NULL)
		return 1;
	return 0;
}

/*���Ӳ���*/
void DeQueue_L(LinkQueue &Q,QNode *q)
{
	QNode *p = new QNode;
	p = Q.front;
	while(p->next == q)
		p = p->next;
	p->next = q->next;
	delete q;
}


/**ɾ������**/  
void QueueDelete(LinkQueue &Q,int type,ElemType &c){
	QNode *p = new QNode;   //ɾ��Ԫ�ص�ǰһ��Ԫ��
	QNode *q = new QNode;   //Ҫɾ����Ԫ��
	p = Q.front;
	int j=0;
	while(j<(type-1)){     //�ҵ�Ҫɾ��Ԫ�ص�ǰһ��Ԫ��
		p = p->next;
		j++;
	}
	q = p->next;
	c = q->data;
	p->next = q->next;
	if((q->next)==NULL)  //��ֻ��һ��Ԫ�ص�ʱ�򣬷�ֹrearָ�붪ʧ����ΪҰָ��
		Q.rear=p;
	delete q;
}

