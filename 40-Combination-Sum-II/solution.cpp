class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        vector<vector<int>> res;
        helper(candidates, res, path, target, 0);
        return res;
    }
    void helper(vector<int>& candidates, vector<vector<int>>& res, vector<int>& path, int target, int start){
        if(target == 0){
            res.push_back(path);
            return;
        }
        int flag = -1;
        for(int i = start; i < candidates.size(); i++){
            if(candidates[i] == flag) continue;
            if(candidates[i] > target) return;
            flag = candidates[i];
            path.push_back(candidates[i]);
            helper(candidates, res, path, target - candidates[i], i + 1);
            path.pop_back();
            
        }
    }
};