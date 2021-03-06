class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        sort(nums.begin(), nums.end());
        helper(res, nums, 0);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& nums, int start) {
        if(start == nums.size() - 1)
            res.push_back(nums);
        for(int i = start; i < nums.size(); i++) {
            swap(nums[i], nums[start]);
            helper(res, nums, start + 1);
            swap(nums[i], nums[start]);
        }
    }
};