class Solution {
public:
    int firstOcc(vector<int>& nums, int target){
        int start = 0;
        int end = nums.size() - 1; 
        int mid = start + (end - start) / 2;
        int ans = -1;
        while (start <= end) {
            mid = start + (end - start) / 2; 
            if (nums[mid] == target) {
                ans = mid;
                end = mid - 1;  
            }
            else if (nums[mid] < target) {
                start = mid + 1;  
            }
            else {  
                end = mid - 1;  
            }
        }
        return ans;
    }
    
    int LastOcc(vector<int>& nums, int target){
        int start = 0;
        int end = nums.size() - 1;  
        int mid = start + (end - start) / 2;
        int ans = -1;
        while (start <= end) {
            mid = start + (end - start) / 2;  
            if (nums[mid] == target) {
                ans = mid;
                start = mid + 1;  
            }
            else if (nums[mid] < target) {
                start = mid + 1;  
            }
            else {  
                end = mid - 1; 
            }
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOcc(nums, target);
        int last = LastOcc(nums, target);
        return {first, last};  
    }
};
