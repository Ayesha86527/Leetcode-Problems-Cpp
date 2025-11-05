class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for (int i=0;i<nums2.size();i++){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(),nums1.end());
        
        if (nums1.size()%2==1){  
            int med_pos=nums1.size()/2;
            double median=nums1[med_pos];
            return median;
        }
        
        int med_pos1=nums1.size()/2 - 1;  
        int med_pos2=nums1.size()/2;      
        double median=(nums1[med_pos1] + nums1[med_pos2]) / 2.0;
        return median;
    }
};