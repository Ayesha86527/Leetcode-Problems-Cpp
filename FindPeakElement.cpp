class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int ans = 0;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            bool leftOk = (mid == 0) || (nums[mid] > nums[mid-1]);
            bool rightOk = (mid == nums.size()-1) || (nums[mid] > nums[mid+1]);
            
            if (leftOk && rightOk) {
                ans = mid;
                return ans;
            }
            else if (mid < nums.size()-1 && nums[mid] < nums[mid+1]) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return 0;
    }
};