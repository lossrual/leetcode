/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
//树上的路径和等于一个target,且记录路径
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        helper(root, sum, res, path);
        return res;
    }
    void helper(TreeNode* root, int sum, vector<vector<int>>& res, vector<int>& path){
        if(!root) return;
        path.push_back(root->val);
        if(!root->left && !root->right) {
            if(root->val == sum) {
                res.push_back(path);
            }
        }
        helper(root->left, sum - root->val, res, path);
        helper(root->right, sum - root->val, res, path);
        path.pop_back();
    }
};