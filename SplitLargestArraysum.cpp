class Solution {
public:
    bool isPossible(vector<int>& nums, int k,int mid){
            int subcount=1;
            int sum=0;
            for (int i=0;i<nums.size();i++){
                if (sum+nums[i]<=mid){
                    sum+=nums[i];
                }
                else {
                    subcount++;
                    sum=nums[i];
                    if (subcount>k){
                        return false;
                    }
                }

            }
            return true;
        }
    int splitArray(vector<int>& nums, int k) {
        int s=*max_element(nums.begin(), nums.end());
        int e=0;
        for (int i=0;i<nums.size();i++){
            e+=nums[i];
        }
        int ans=-1;
        int mid=s+(e-s)/2;
        while (s<=e){
            if (isPossible(nums,k,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
};