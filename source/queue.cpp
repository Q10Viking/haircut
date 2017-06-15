#include "common.h"
#include "queue.h"

/*异常处理*/
void Error(char *s)
{cout<<s<<endl;}



/*初始化节点*/
void InitQueue_L(LinkQueue &Q){
	Q.front = Q.rear = new QNode;
	Q.front->next = NULL;
}
/*销毁链表*/
void DestroyList_L(LinkQueue &Q){
	while(Q.front){
		Q.rear = Q.front->next;
		delete Q.front;
		Q.front = Q.rear;
	}
}
/*求表长*/
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
/*入队操作*/
void EnQueue_L(LinkQueue &Q,ElemType e)
{
	QNode *p = new QNode;
	p->data = e; 
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
}

/*判断是否为空*/
int Empty_L(LinkQueue &Q){
	if(Q.front->next == NULL)
		return 1;
	return 0;
}

/*出队操作*/
void DeQueue_L(LinkQueue &Q,QNode *q)
{
	QNode *p = new QNode;
	p = Q.front;
	while(p->next == q)
		p = p->next;
	p->next = q->next;
	delete q;
}


/**删除操作**/  
void QueueDelete(LinkQueue &Q,int type,ElemType &c){
	QNode *p = new QNode;   //删除元素的前一个元素
	QNode *q = new QNode;   //要删除的元素
	p = Q.front;
	int j=0;
	while(j<(type-1)){     //找到要删除元素的前一个元素
		p = p->next;
		j++;
	}
	q = p->next;
	c = q->data;
	p->next = q->next;
	if((q->next)==NULL)  //当只有一个元素的时候，防止rear指针丢失，成为野指针
		Q.rear=p;
	delete q;
}

