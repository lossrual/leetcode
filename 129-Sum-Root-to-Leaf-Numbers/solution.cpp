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
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        vector<int> res;
        int path;
        path = root->val;
        helper(root, res, path);
        int sum = 0;
        for(auto& c: res){
            sum += c;
        }
        return sum;
    }
    void helper(TreeNode* root, vector<int>& res, int path){
        if(!root) return;
        if(!root->left && !root->right){
            res.push_back(path);
        }
        if(root->left) helper(root->left, res, 10 * path + root->left->val);
        if(root->right) helper(root->right, res, 10 * path + root->right->val);
    }
    
};