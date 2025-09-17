class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        for (int i=0;i<m;i++){
            int n=matrix[i].size();
            for (int j=0;j<n;j++){
                if (target==matrix[i][j]){
                    return true;
                }
            }
        }
        return false;
        
    }
};