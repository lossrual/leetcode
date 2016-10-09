class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        vector<int> count(32, 0);
        for(int i = 0; i < 32; i++) {
            for(int j = 0; j < nums.size(); j++) {
                if(nums[j] >> i & 1)
                    count[i]++;
            }
            res |= ((count[i] % 3) << i);
        }
        return res;
    }
};