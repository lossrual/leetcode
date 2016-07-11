class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int i = 0, j = 0;
        int minn = INT_MAX, sum = 0;
        while(j < nums.size()){
            sum += nums[j++];
            while(sum >= s){
                minn = min(minn, (j - i));
                sum -= nums[i++];
            }
        }
        return minn == INT_MAX ? 0 : minn;
    }
};