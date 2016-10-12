class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int cnt = 0;
        for(auto c: nums) {
            if(c == candidate)
                cnt++;
            else
                cnt--;
            if(cnt == 0) {
                candidate = c;
                cnt = 1;
            }
        }
        return candidate;
    }
};