class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        int maxp = 0;
        if(nums.size() == 1) return 1; 
        for(int i = 0; i < nums.size(); i++){
            dp[i] = 1;
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i] && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
                maxp = max(maxp, dp[i]);
            }    
        }
        return maxp;
    }
};