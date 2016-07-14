class Solution {
    typedef unsigned long long ull;
public:
    vector<vector<int>> subsets1(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        sort(nums.begin(), nums.end());
        helper(res, path, nums, 0);
        return res;
    }
    vector<vector<int>> subsets2(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        sort(nums.begin(), nums.end());
        res.push_back(path);
        for(int i = 0; i < nums.size(); i++){
            int n = res.size();
            for(int j = 0; j < n; j++){
                path = res[j];
                path.push_back(nums[i]);
                res.push_back(path);
            }
        }
        return res;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        ull maxn = pow(2, nums.size()) - 1;
        for(ull i = 0; i <= maxn; i++){
            res.push_back(helper(nums, i));
        }
        return res;
    }
    vector<int> helper(vector<int>& nums, ull maxn){
        vector<int> path;
        int i = 0;
        while(maxn){
            if(maxn & 0x1) path.push_back(nums[i]);
            maxn >>= 1;
            i++;
        }
        return path;
    }
private:
    void helper(vector<vector<int>>& res, vector<int>& path, vector<int>& nums, int start){
        res.push_back(path);
        for(int i = start; i < nums.size(); i++){
            path.push_back(nums[i]);
            helper(res, path, nums, i + 1);
            path.pop_back();
        }
    }
};