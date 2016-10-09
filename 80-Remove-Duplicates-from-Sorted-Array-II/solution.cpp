class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 2;
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        for(int i = 2; i < nums.size(); i++) {
            if(nums[index - 2] != nums[i])
                nums[index++] = nums[i];
        }
        return index;
    }
};