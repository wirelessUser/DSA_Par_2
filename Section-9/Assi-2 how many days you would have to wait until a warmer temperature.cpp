#include <bits/stdc++.h>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Outscal {
public:
  vector<int> temperatures(vector<int> temps) {
      int len= temps.size();
     stack<int> tempStack;
     unordered_map<int,int>  res;
     
     
     for(int i=len-1; i>=0;i--){
     	
     	
     	while(!tempStack.empty() && temps[i]>=temps[tempStack.top()]){
     		tempStack.pop();
		 }//while...
		if(tempStack.empty()){
		    res[temps[i]]=0;
		}
		 else if(temps[i]<temps[tempStack.top()]){
		 	int prevIndex= tempStack.top();
		 	res[temps[i]]= prevIndex-i;
		 }
		 	tempStack.push(i);
		 
     	
	 }//for...
 
       vector<int>  resFinal(temps.size(),0);
       
  for(int i=0; i<len-1;i++){
        
        resFinal[i]= res[temps[i]];
    }
 return resFinal;
  }//temperatures..
};

//***********************************
// DO NOT MODIFY THE MAIN FUNCTION
// ELSE YOU SUBMISSION WILL BE DISQUALIFIE

int main() {
  int m, i;
  int temp;
  vector<int> brr;
  cin >> m;
  while (m) {
    cin >> temp;
    brr.push_back(temp);
    m--;
  }
  class Outscal s;
  vector<int> ans = s.temperatures(brr);
  for (i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  return (0);
}

