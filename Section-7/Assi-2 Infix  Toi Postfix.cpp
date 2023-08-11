#include <iostream>
#include<stack>
using namespace std;

// Stack = Last in  First Out....




int ReverseNum(int num){
	
	int originalNum= num;
	stack<int> myStack;
int multuplier=1;
    int res=0;
   
   
   while(num!=0){
   	cout<<num%10<<"num%10"<<endl;
   	myStack.push(num%10);
   	num/=10 ;
   }
   
   while(!myStack.empty()){
   	
   	int top= myStack.top();
   	myStack.pop();
   	
   	res+= top*multuplier;
   	multuplier*=10;
   	
   }
   
      while (originalNum % 10 == 0 && originalNum != 0) {
    res *= 10;
    originalNum /= 10;
  }
  
   
   return res;
   
}//ReverseNum.,....


int main() {
 
int number1 = 120;
  int number2 = 12340;
  int number3 = 1;

  cout << "Orginal num== " << number1<<endl;
       cout<< ", Reversed Number: " << ReverseNum(number1) << endl;


  return 0;
}







