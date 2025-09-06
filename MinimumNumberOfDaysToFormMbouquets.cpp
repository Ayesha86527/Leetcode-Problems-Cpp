class Solution {
public:
    bool ispossible(vector<int>& bloomDay, int m, int k, int mid) {
        int fCount = 0;    
        int bouq = 0;       

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= mid) {
                fCount++;
                if (fCount == k) { 
                    bouq++;
                    fCount = 0;  
                }
            } else {
                fCount = 0; 
            }
        }

        return bouq >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalNeeded = 1LL * m * k;
        if (bloomDay.size() < totalNeeded) return -1;

        int s = *min_element(bloomDay.begin(), bloomDay.end());
        int e = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (ispossible(bloomDay, m, k, mid)) {
                ans = mid;
                e = mid - 1;   
            } else {
                s = mid + 1;   
            }
        }
        return ans;
    }
};
