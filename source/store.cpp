#include "store.h"
#include "common.h"
void InitStore(Store &s){    //初始化理发店  

	//s.p1 = new LinkQueue;     //一级队列            //这里还有问提
	//s.p2 = new LinkQueue;     //二级队列
	//s.p3 = new LinkQueue;     //三级队列  

	InitQueue_L(s.p1);   //一级队列              //解决问题
	InitQueue_L(s.p2);	 //二级队列
	InitQueue_L(s.p3);   //三级队列  

	s.totalTime = 0;         //总时间设置为0
	int i=0;
	for(int i=0;i<3;i++)
		s.Money[i] = 0;		//初始化每个理发师的营业额  
	s.totalMoney = 0; 
}  

void goToStore(Store &s,Customer c){     //顾客进入理发店  
	int select=c.select;
	if(select == 1){     //选择一级理发师的顾客
		//p1队列的入队  
		EnQueue_L(s.p1,c);
	}

	if(select == 2){     //选择二级理发师的顾客
		//p2队列的入队
		EnQueue_L(s.p2,c);
	}

	if(select == 3){     //选择三级理发师的顾客
		//p3队列的入队
		EnQueue_L(s.p3,c);
	}
}  


bool beforeNextOne(Store &s,Customer c){		//在下一个顾客进店之前处理，理发时间 
	//获取下一个顾客将要到来的时间  
	int nextCustTime = c.intertime;  

	//在下一个顾客到来时，计算正在理发的顾客remainTime剩余时间  
	
	//============P1=======================================
	//处理p1的前两个位置的顾客理发  
		
	//如果队列不为空，处理p1 
	if( !Empty_L(s.p1)){
		//处理p1的第一个位置  
			QNode *person1 = new QNode;   
			QNode *person2 = new QNode; 
			bool flag1=true,flag2=false;
			person2=NULL;

			person1 = s.p1.front->next;   //获取到第一个正在理发的顾客 
			//处理时间
			(person1->data).remainTime -= nextCustTime;

			//在处理p1中如果长度大于等于二处理第二个位置  
			int length = ListLength_L(s.p1);
			if(length>1){
				person2 = person1->next;   //获得第二个正在理发的顾客  
				//处理时间
				(person2->data).remainTime -= nextCustTime;
				flag2=true;
			}



			//在处理完这个位置后，判断是否还有剩余时间，没有则收费，并离开理发位置
			if(flag2){
				int remain2 = (person2->data).remainTime;
				//判断剩余时间
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
		//处理p2的第一个位置  
			QNode *person1 = new QNode;   
			QNode *person2 = new QNode; 
			bool flag1=true,flag2=false;  //因为能够进来处理，那么肯定会有顾客1在理发，所以flag1=true
			int length = ListLength_L(s.p2);

			person2=NULL;
			person1 = s.p2.front->next;   //获取到第一个正在理发的顾客 
			//处理时间
			(person1->data).remainTime -= nextCustTime;

			//在处理p2中如果长度大于等于二处理第二个位置  
			
			
			if(length>1){
				person2 = person1->next;   //获得第二个正在理发的顾客  
				//处理时间
				(person2->data).remainTime -= nextCustTime;
				flag2=true;
			}

			//在处理完这个位置后，判断是否还有剩余时间，没有则收费，并离开理发位置
			
			if(flag2){
				int remain2 = (person2->data).remainTime;
				//判断剩余时间
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
	//处理p3的前三个位置的顾客理发，如果队列不为空，处理p3  
	if( !Empty_L(s.p3)){
		QNode *person1 = new QNode;   
		QNode *person2 = new QNode; 
		QNode *person3 = new QNode; 
		bool flag1=true,flag2=false,flag3=false;
		person2=person3=NULL;
		int length = ListLength_L(s.p3);   //获取长度  

	    person1 = s.p3.front->next;   //获取到第一个正在理发的顾客 
	   (person1->data).remainTime -= nextCustTime;   //处理时间  

	   if(length>1){
		    person2 = person1->next;   //获取到第二正在理发的顾客 
		    (person2->data).remainTime -= nextCustTime;   //处理时间 
			flag2=true;
	   }
	   if(length>2){
		   person3 = person2->next;   //获取到第三正在理发的顾客 
		   (person3->data).remainTime -= nextCustTime;   //处理时间  
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
	//累加这个时间到s.totalTime总时间中，判断是否大于等于480  
	s.totalTime += nextCustTime;
	if(s.totalTime>480){     
		//此时已经结束，排队的人不再坐到座位上 ，而各个理发室需要处理完成理发进行中的顾客  
		int i=0;  
		cout<<"时间已到，不再接客："<<endl;
		QNode *First = new QNode;   //处理一级理发中顾客  
		First = s.p1.front->next;  
		for(i=0;i<2;i++){
			if(First == NULL){
				break;
			}
			calcMoney(s,First->data);   //收钱  
			First = First->next;
		}


		QNode *Second = new QNode;   //处理二级理发中顾客  
		Second = s.p2.front->next;  
		for(i=0;i<2;i++){
			if(Second == NULL){
				break;
			}
			calcMoney(s,Second->data);   //收钱  
			Second = Second->next;
		}  

		QNode *Third = new QNode;   //处理三级理发中顾客  
		Third = s.p3.front->next;  
		for(i=0;i<3;i++){
			if(Third == NULL){
				break;
			}
			calcMoney(s,Third->data);   //收钱  
			Third = Third->next;
		}
		return false;
	}
	return true;
} 

void goOutStore(Store &s,LinkQueue &p,int type){			//理发结束的顾客离开理发店  
	//将元素弹出并计算收费以及自动补充排队的人数
	Customer c;
	QueueDelete(p,type,c);
	calcMoney(s,c);  
}  

void calcMoney(Store &s,Customer c){    //计算理发介绍后，理发店的收取费用
	s.Money[c.select-1] += c.durtime*(4-c.select)*0.4;
} 

double getTotalMoney(Store &s){       //获取理发店的营业额
	return (s.Money[0]+s.Money[1]+s.Money[2]);
}


double getMoneyOfFirst(Store &s){    //获取一级理发室的收入
	return s.Money[0];
}
double getMoneyOfSecond(Store &s){    //获取二级理发室的收入
	return s.Money[1];
}
double getMoneyOfThird(Store &s){    //获取三级理发室的收入  
	return s.Money[2];
}

