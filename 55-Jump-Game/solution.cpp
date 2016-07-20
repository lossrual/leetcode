class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0) return false;
        int reach = 0;
        for(int i = 0; i < nums.size() && i <= reach; i++){
            reach = max(nums[i] + i, reach);
        }
        return reach >= nums.size() - 1;
    }
};