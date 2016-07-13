class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /*
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
        */
        reverse(nums.begin(), nums.begin() + k + 1);
        reverse(nums.begin() + k + 1, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
