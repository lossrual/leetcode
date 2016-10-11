class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0], maxp = nums[0];
        int begin = 0, cur = 0, end = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(sum < 0) {
                sum = nums[i];
                begin = i;
            }else {
                sum += nums[i];
            }
            if(sum > maxp){
                maxp = sum;
                cur = begin;
                end = i;
            }
        }
        std::cout << cur << ' ' << end << std::endl;
        return maxp;
    }
};