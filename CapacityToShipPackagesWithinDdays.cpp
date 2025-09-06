class Solution {
public:
    bool isPossible(vector<int>& weights, int n, int days, int mid){
        int day_count = 1;
        int cap = 0;

        for (int i = 0; i < n; i++){
            if (cap + weights[i] <= mid){
                cap += weights[i];
            }
            else{
                day_count += 1;
                cap = weights[i]; 
                if (day_count > days || weights[i] > mid){
                    return false;
                }
            }
        }
        return true;
    }

     int shipWithinDays(vector<int>& weights, int days) {
        int s = 0;
        int sum = 0;
        for (int i = 0; i < weights.size(); i++){
            sum += weights[i]; 
        }
        int e = sum;
        int ans = -1;
        int mid = s + (e - s) / 2;
        while (s <= e){ 
            if (isPossible(weights, weights.size(), days, mid)){  
               ans = mid;
               e = mid - 1;
            }
            else{
                s = mid + 1;
            }
            mid = s + (e - s) / 2;
        }
        return ans;
    }
};
