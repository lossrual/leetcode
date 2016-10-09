class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return {};
        int res = 0;
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0]; dp[1] = max(nums[0],nums[1]);
        for(int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);//状态转移
        }
        return dp[nums.size() - 1];
    }
};