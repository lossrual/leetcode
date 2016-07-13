class Solution {
public:
    vector<vector<int>> permuteUnique1(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() == 0) return res;
        sort(nums.begin(), nums.end());
        res.push_back(nums);
        while(next_permutation(nums)){
            res.push_back(nums);
        }
        return res;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> used(nums.size(), 0);
        vector<int> path;
        //if(nums.size() == 0) return res;
        sort(nums.begin(), nums.end());
        //res.push_back(nums);
        helper(nums, res, path, used);
        return res;
    }/*
    void helper(vector<int>& nums, vector<vector<int>>& res, int k){
        if(k == nums.size() - 1){
            res.push_back(nums);
            return;
        }
        for(int i = k; i <= nums.size() - 1; i++){
            if(i != k && nums[i] == nums[k]) continue;
            swap(nums[i], nums[k]);
            helper(nums, res, k + 1);
            swap(nums[i], nums[k]);
        }
    }*/
    
    void helper(vector<int> nums, vector<vector<int>>& res, vector<int>& path, vector<bool>& used){
        if(path.size() == nums.size()){
            res.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(used[i] || (i>0 && nums[i]==nums[i-1] && used[i-1] )) continue;
            used[i] = true;
            path.push_back(nums[i]);
            helper(nums, res, path, used);
            used[i] = false;
            path.pop_back();
        }
    }
    void solve(vector<int>& nums,vector<int>& curr, vector<vector<int>>& res, vector<bool>& used)
    {
        if(curr.size()==nums.size())
        {
            res.push_back(curr);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
           if(used[i] || (i>0 && nums[i]==nums[i-1] && used[i-1] ))
            continue;
            used[i]=true;
            curr.push_back(nums[i]);
            solve(nums,curr,res,used);
            used[i]=false;
            curr.pop_back();
        }
    }

    vector<vector<int>> permuteUnique2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > res;
        vector<int> curr;
        vector<bool> used(nums.size(),0);
        solve(nums,curr,res,used);
        return res;
    }
    bool next_permutation(vector<int>& nums){
        int i = nums.size() - 2;
        while(i >= 0 && nums[i] >= nums[i + 1]){
            i--;
        }
        int j = i + 1;
        if(i >= 0){
            while(j < nums.size() && nums[j] > nums[i]){
                ++j;
            }
            --j;
            swap(nums[i], nums[j]);
        }else{
            return false;
        }
        reverse(nums.begin() + i + 1, nums.end());
        return true;
    }
    
};