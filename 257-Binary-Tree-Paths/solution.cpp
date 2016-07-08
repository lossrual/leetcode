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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root) return res;
        string path;
        path += to_string(root->val);
        helper(root, res, path);
        return res;
    }
    void helper(TreeNode* root, vector<string>& res, string path){
        if(!root) return;
        if(!root->left && !root->right){
            res.push_back(path);
            return;
        }
        if(root->left) helper(root->left, res, path + "->" + to_string(root->left->val));
        if(root->right) helper(root->right, res, path + "->" + to_string(root->right->val));
        //path.erase(path.end() - 1);
    }
};