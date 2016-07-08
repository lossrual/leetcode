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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return height(root) >= 0;
    }
    int height(TreeNode* root){
        if(!root) return 0;
        int left = height(root->left), right = height(root->right);
        if(left < 0 || right < 0 || abs(left - right) > 1) return -1;
        return max(height(root->left), height(root->right)) + 1;
    }
};