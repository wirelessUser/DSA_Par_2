vector<int> commonPrefix (vector<int> nums1,vector<int> nums2) { 
      int n = nums2.size();
        stack<int> s;
        map<int, int> ans_nums2;

                //iterate from last to first element in the vector nums2
        for(int i = n - 1; i >= 0; i--) {
                        //keep popping elements out from stack until stack is
                        //empty or the top element of stack has value greater
                        //than nums2[i]
            while(s.size() && s.top() < nums2[i]) {
                s.pop();
            }
                        //now the top element of stack will be the next greater
                        //element of nums2[i]
            if(s.empty()) {
                                //No greater element exist for nums2[i]
                ans_nums2[nums2[i]] = -1;
            } else {
                ans_nums2[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }
        
        
        
        
        vector<int> ans(nums1.size());
        for(int i = 0; i < nums1.size(); i++){
            ans[i] = ans_nums2[nums1[i]];
        }
        return ans;
 }
