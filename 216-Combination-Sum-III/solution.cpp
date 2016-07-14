class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> path;
        helper(res, path, k, n, 1);
        return res;
    }
    void helper(vector<vector<int>>& res, vector<int>& path, int k, int n, int start){
        if(k == 0 && n == 0){
            res.push_back(path);
            return;
        }
        for(int i = start; i <= 10 - k && i <= n; i++){
            path.push_back(i);
            helper(res, path, k - 1, n - i, i + 1);
            path.pop_back();
        }
    }
};