class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minp = nums[0];
        int maxp = nums[0];
        int maxn = nums[0];
        //int start = 0, end = 0, curstart = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] >= 0){
                maxp = max(maxp * nums[i], nums[i]);
                minp = min(minp * nums[i], nums[i]);
            }else{
                int tmp = maxp;
                maxp = max(minp * nums[i], nums[i]);
                minp = min(tmp * nums[i], nums[i]);
            }
            maxn = max(maxn, maxp);
        }
        return maxn;
    }
};