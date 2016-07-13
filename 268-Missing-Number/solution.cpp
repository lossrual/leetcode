class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size() + 1;
        int sum = 0;
        for(auto c: nums)
            sum += c;
        return n * (n - 1) / 2 - sum;
    }
    //int missingNumber(vector<int>& nums) {
        
        
    //}
};