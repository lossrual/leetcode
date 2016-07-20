class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int maxn = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(sum < 0){
                sum = nums[i];
            }else{
                sum += nums[i];
            }
            if(sum > maxn){
                maxn = sum;
            }
        }
        return maxn;
    }
};