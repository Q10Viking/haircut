#include "result.h"
#include "common.h"

void getResult(Store store,double &totalMoney,double Money[]){
	totalMoney = getTotalMoney(store);
	Money[0] =getMoneyOfFirst(store);
	Money[1] =getMoneyOfSecond(store);
	Money[2] =getMoneyOfThird(store); 

}

void printResult(double totalMoney,double Money[]){
	cout<<"理发店在480分钟内的营业额为："<<endl;
	cout<<totalMoney<<endl;
	for(int i=0;i<3;i++){
		cout<<"第"<<i+1<<" 级理发室的收入"<<Money[i]<<endl;
	}
}
void printChart(double totalMoney,double Money[]){

}