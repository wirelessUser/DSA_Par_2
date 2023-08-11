#include <bits/stdc++.h>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Outscal {
public:
 vector<int> NextGreater (vector<int> nums1,vector<int> nums2) { 
      int n = nums2.size();
        stack<int> s;
        map<int, int> ans_nums2;
                 
                //iterate from last to first element in the vector nums2
        for(int i = n - 1; i >= 0; i--) {
        	
        	
                        
            while(s.size() && s.top() <= nums2[i]) {
                s.pop();
            }
                       
            if(s.empty()) {
                                //No greater element exist for nums2[i]
                               // if there is no greater means all elemenst from stack will removed an dnow stack 
							   //is emepty Means that element have no next grtaeter element
                            // The last elem,ent alweays have -1 as there is no element after it so it dont have any enxt graeter element.   
                               
                ans_nums2[nums2[i]] = -1;
            } else {
                ans_nums2[nums2[i]] = s.top();
            }
            // first check the Next greater for that element then Push it other wise Wrong Result wil be Shown By The Code...
            s.push(nums2[i]);
        }
        vector<int> ans(nums1.size());
        for(int i = 0; i < nums1.size(); i++){
            ans[i] = ans_nums2[nums1[i]];
        }
        return ans;
 }
};

//***********************************
// DO NOT MODIFY THE MAIN FUNCTION
// ELSE YOU SUBMISSION WILL BE DISQUALIFIED
//***********************************

int main() {
  int m, temp, i, n;
  vector<int> brr, arr;
   cout << "Give valu eof m and n" << endl;
  cin >> m >> n;
  while (m) {
     cout << "Give value of temp inside m " << endl;
    cin >> temp;
    brr.push_back(temp);
    m--;
  }
  while (n) {
     cout << "Give value of temp inside n " << endl;
    cin >> temp;
    arr.push_back(temp);
    n--;
  }
  class Outscal s;
  vector<int> ans = s.NextGreater(brr, arr);
  for (i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  return 0;
}

