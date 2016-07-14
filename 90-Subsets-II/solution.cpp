class Solution {
    typedef unsigned long long ull;
public:
    vector<vector<int>> subsetsWithDup1(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        sort(nums.begin(), nums.end());
        helper(res, path, nums, 0);
        return res;
    }
    /*
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        //vector<int> path;
        sort(nums.begin(), nums.end());
        ull maxn = pow(2, nums.size()) - 1;
        for(ull i = 0; i <= maxn; i++){
            res.push_back(helper(nums, i));
        }
        return res;
    }
private:
    vector<int> helper(vector<int>& nums, ull maxn){
        int i = 0;
        vector<int> path;
        while(maxn){
            if(nums[i] == nums[i - 1]) continue;
            //std::cout << 1;
            if(maxn & 0x1) path.push_back(nums[i]);
            maxn >>= 1;
            i++;
        }
        return path;
    }
    */
    void helper(vector<vector<int>>& res, vector<int>& path, vector<int>& nums, int start){
        res.push_back(path);
        for(int i = start; i < nums.size(); i++){
            if(i > start && nums[i] == nums[i - 1]) continue;
            path.push_back(nums[i]);
            helper(res, path, nums, i + 1);
            path.pop_back();
        }
    }
};