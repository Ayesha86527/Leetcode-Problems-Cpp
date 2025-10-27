class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> result(n, -1);
        stack<int> s;
    
        for (int i = 2*n - 1; i >= 0; i--) {
            int idx = i % n;
            while (!s.empty() && s.top() <= nums[idx]) {
                s.pop();
            }
            
            if (i < n) {
                if (s.empty()) {
                    result[idx] = -1;  
                } else {
                    result[idx] = s.top();  
                }
            }
            
            s.push(nums[idx]);
        }
        
        return result;
    }
};