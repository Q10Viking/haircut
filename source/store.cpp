#include "store.h"
#include "common.h"
void InitStore(Store &s){    //��ʼ������  

	//s.p1 = new LinkQueue;     //һ������            //���ﻹ������
	//s.p2 = new LinkQueue;     //��������
	//s.p3 = new LinkQueue;     //��������  

	InitQueue_L(s.p1);   //һ������              //�������
	InitQueue_L(s.p2);	 //��������
	InitQueue_L(s.p3);   //��������  

	s.totalTime = 0;         //��ʱ������Ϊ0
	int i=0;
	for(int i=0;i<3;i++)
		s.Money[i] = 0;		//��ʼ��ÿ����ʦ��Ӫҵ��  
	s.totalMoney = 0; 
}  

void goToStore(Store &s,Customer c){     //�˿ͽ�������  
	int select=c.select;
	if(select == 1){     //ѡ��һ����ʦ�Ĺ˿�
		//p1���е����  
		EnQueue_L(s.p1,c);
	}

	if(select == 2){     //ѡ�������ʦ�Ĺ˿�
		//p2���е����
		EnQueue_L(s.p2,c);
	}

	if(select == 3){     //ѡ��������ʦ�Ĺ˿�
		//p3���е����
		EnQueue_L(s.p3,c);
	}
}  


bool beforeNextOne(Store &s,Customer c){		//����һ���˿ͽ���֮ǰ������ʱ�� 
	//��ȡ��һ���˿ͽ�Ҫ������ʱ��  
	int nextCustTime = c.intertime;  

	//����һ���˿͵���ʱ�������������Ĺ˿�remainTimeʣ��ʱ��  
	
	//============P1=======================================
	//����p1��ǰ����λ�õĹ˿���  
		
	//������в�Ϊ�գ�����p1 
	if( !Empty_L(s.p1)){
		//����p1�ĵ�һ��λ��  
			QNode *person1 = new QNode;   
			QNode *person2 = new QNode; 
			bool flag1=true,flag2=false;
			person2=NULL;

			person1 = s.p1.front->next;   //��ȡ����һ���������Ĺ˿� 
			//����ʱ��
			(person1->data).remainTime -= nextCustTime;

			//�ڴ���p1��������ȴ��ڵ��ڶ�����ڶ���λ��  
			int length = ListLength_L(s.p1);
			if(length>1){
				person2 = person1->next;   //��õڶ����������Ĺ˿�  
				//����ʱ��
				(person2->data).remainTime -= nextCustTime;
				flag2=true;
			}



			//�ڴ��������λ�ú��ж��Ƿ���ʣ��ʱ�䣬û�����շѣ����뿪��λ��
			if(flag2){
				int remain2 = (person2->data).remainTime;
				//�ж�ʣ��ʱ��
				if(remain2<=0)
					goOutStore(s,s.p1,2);
			}
			if(flag1){
				int remain1 = (person1->data).remainTime;
				if(remain1<=0)
					goOutStore(s,s.p1,1);
			}

	}
	//============P2=======================================  

	if( !Empty_L(s.p2)){
		//����p2�ĵ�һ��λ��  
			QNode *person1 = new QNode;   
			QNode *person2 = new QNode; 
			bool flag1=true,flag2=false;  //��Ϊ�ܹ�����������ô�϶����й˿�1����������flag1=true
			int length = ListLength_L(s.p2);

			person2=NULL;
			person1 = s.p2.front->next;   //��ȡ����һ���������Ĺ˿� 
			//����ʱ��
			(person1->data).remainTime -= nextCustTime;

			//�ڴ���p2��������ȴ��ڵ��ڶ�����ڶ���λ��  
			
			
			if(length>1){
				person2 = person1->next;   //��õڶ����������Ĺ˿�  
				//����ʱ��
				(person2->data).remainTime -= nextCustTime;
				flag2=true;
			}

			//�ڴ��������λ�ú��ж��Ƿ���ʣ��ʱ�䣬û�����շѣ����뿪��λ��
			
			if(flag2){
				int remain2 = (person2->data).remainTime;
				//�ж�ʣ��ʱ��
				if(remain2<=0)
					goOutStore(s,s.p2,2);
			}
			if(flag1){
				int remain1 = (person1->data).remainTime;
				if(remain1<=0)
					goOutStore(s,s.p2,1);
			}
	}
	//============P3=======================================  
	//����p3��ǰ����λ�õĹ˿�����������в�Ϊ�գ�����p3  
	if( !Empty_L(s.p3)){
		QNode *person1 = new QNode;   
		QNode *person2 = new QNode; 
		QNode *person3 = new QNode; 
		bool flag1=true,flag2=false,flag3=false;
		person2=person3=NULL;
		int length = ListLength_L(s.p3);   //��ȡ����  

	    person1 = s.p3.front->next;   //��ȡ����һ���������Ĺ˿� 
	   (person1->data).remainTime -= nextCustTime;   //����ʱ��  

	   if(length>1){
		    person2 = person1->next;   //��ȡ���ڶ��������Ĺ˿� 
		    (person2->data).remainTime -= nextCustTime;   //����ʱ�� 
			flag2=true;
	   }
	   if(length>2){
		   person3 = person2->next;   //��ȡ�������������Ĺ˿� 
		   (person3->data).remainTime -= nextCustTime;   //����ʱ��  
		   flag3=true;   
	   }

	   if(flag3){
		   int remain3 = (person3->data).remainTime;
		   if(remain3<=0)
			   goOutStore(s,s.p3,3);
	   }

	   if(flag2){
		    int remain2 = (person2->data).remainTime;
			 if(remain2<=0)
			   goOutStore(s,s.p3,2);
	   }
	   if(flag1){
		    int remain1 = (person1->data).remainTime;
			 if(remain1<=0)
			   goOutStore(s,s.p3,1);
	   }
	}
  //=========================================================  
	//�ۼ����ʱ�䵽s.totalTime��ʱ���У��ж��Ƿ���ڵ���480  
	s.totalTime += nextCustTime;
	if(s.totalTime>480){     
		//��ʱ�Ѿ��������Ŷӵ��˲���������λ�� ��������������Ҫ��������������еĹ˿�  
		int i=0;  
		cout<<"ʱ���ѵ������ٽӿͣ�"<<endl;
		QNode *First = new QNode;   //����һ�����й˿�  
		First = s.p1.front->next;  
		for(i=0;i<2;i++){
			if(First == NULL){
				break;
			}
			calcMoney(s,First->data);   //��Ǯ  
			First = First->next;
		}


		QNode *Second = new QNode;   //����������й˿�  
		Second = s.p2.front->next;  
		for(i=0;i<2;i++){
			if(Second == NULL){
				break;
			}
			calcMoney(s,Second->data);   //��Ǯ  
			Second = Second->next;
		}  

		QNode *Third = new QNode;   //�����������й˿�  
		Third = s.p3.front->next;  
		for(i=0;i<3;i++){
			if(Third == NULL){
				break;
			}
			calcMoney(s,Third->data);   //��Ǯ  
			Third = Third->next;
		}
		return false;
	}
	return true;
} 

void goOutStore(Store &s,LinkQueue &p,int type){			//�������Ĺ˿��뿪����  
	//��Ԫ�ص����������շ��Լ��Զ������Ŷӵ�����
	Customer c;
	QueueDelete(p,type,c);
	calcMoney(s,c);  
}  

void calcMoney(Store &s,Customer c){    //���������ܺ��������ȡ����
	s.Money[c.select-1] += c.durtime*(4-c.select)*0.4;
} 

double getTotalMoney(Store &s){       //��ȡ�����Ӫҵ��
	return (s.Money[0]+s.Money[1]+s.Money[2]);
}


double getMoneyOfFirst(Store &s){    //��ȡһ�����ҵ�����
	return s.Money[0];
}
double getMoneyOfSecond(Store &s){    //��ȡ�������ҵ�����
	return s.Money[1];
}
double getMoneyOfThird(Store &s){    //��ȡ�������ҵ�����  
	return s.Money[2];
}

