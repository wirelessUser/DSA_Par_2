#include <bits/stdc++.h>
#include <stack>
using namespace std;

class Outscal {
public:
  int game(vector<string> ops) {
   int len= ops.size();
   stack<int>  record;
   int sum;
   
   for (string op : ops){
   	
   	  if(op=="+"){
   	  	  if(!record.empty()){
   	  	  	 	int prev1= record.top();
		 	record.pop();
		 	
		 	int prev2= record.top();
		 	record.push(prev1);
		 
		 	
		 	record.push(prev1+prev2);
			   }//if
   	  	 
		 }else if(op== "D"){
		 
		 	if(!record.empty()) {
		 		record.push(record.top()*2);
			 }
		 	
		 }else if(op== "C"){
		 	
		 	if(!record.empty()){
		 		record.pop();
			 } 
		 }else{
		 	int num = stoi(op);
		 	record.push(num);
		 }
   }//for...


 while (!record.empty()) {
      sum += record.top();
      record.pop();
    }

return sum;
  }//game Func..
};

//***********************************
// DO NOT MODIFY THE MAIN FUNCTION
// ELSE YOU SUBMISSION WILL BE DISQUALIFIED
//***********************************

int main() {
  int m;
  string temp;
  vector<string> brr;
  cin >> m;
  while (m) {
    cin >> temp;
    brr.push_back(temp);
    m--;
  }
  class Outscal s;
  int ans = s.game(brr);
  cout << ans;
  return (0);
}

