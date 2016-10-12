class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxp = nums[0], minp = nums[0], res = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] >= 0) {
                maxp = max(maxp * nums[i], nums[i]);
                minp = min(minp * nums[i], nums[i]);
            }else {
                int tmp = maxp;
                maxp = max(minp * nums[i], nums[i]);
                minp = min(tmp * nums[i], nums[i]);
            }
            res = max(maxp, res);
        }
        return res;
    }
};