class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        int size = nums.size();
        
        for (int i = 0; i < size; i++) {
            if (nums[i] == 0) {
                count += 1;
            }
        }
        
        int writeIndex = 0;
        for (int i = 0; i < size; i++) {
            if (nums[i] != 0) {
                nums[writeIndex] = nums[i];
                writeIndex++;
            }
        }
        for (int i = size - count; i < size; i++) {
            nums[i] = 0;
        }
    }
};