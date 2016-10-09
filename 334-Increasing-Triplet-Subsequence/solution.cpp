class Solution {
public:
    bool increasingTriplet1(vector<int>& nums) {
        int c1 = INT_MAX, c2 = INT_MAX;
        for(auto& x: nums){
            if(x <= c1){
                c1 = x;
            }else if(x <= c2){
                c2 = x;
            }else{
                return true;
            }
        }
        return false;
    }
    bool increasingTriplet(vector<int>& nums) {
        return helper(nums) >= 3;
    }
    int helper(vector<int>& nums) {
        int dp[100000];
        int maxp = 0;
        dp[0] = 0;
        for(int i = 0; i < nums.size(); i++) {
            dp[i] = 1;
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j] && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
                 maxp = max(maxp, dp[i]);
            }
        }
        return maxp;
    }
};