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
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return root->val;
        vector<int> left; vector<int> right;
        int path = root->left->val;
        helper(root->left, left, path);
        path = root->right->val;
        helper(root->right, right, path);
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        //std::cout << left[left.size() - 1] << ' ' << right[right.size() - 1] << std::endl;
        return left[left.size() - 1] + right[right.size() - 1] + root->val;
    }
    void helper(TreeNode* root, vector<int>& res, int path){
        if(!root) return;
        if(!root->left && !root->right){
            res.push_back(path);
            return;
        }
        if(root->left) helper(root->left, res, path + root->left->val);
        if(root->right) helper(root->right, res, path + root->right->val);
    }
};