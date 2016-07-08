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
    int maxDepth(TreeNode* root) {
        return depth(root);
    }
    int depth(TreeNode* root){
        if(!root) return 0;
        if(!root->left) return depth(root->right) + 1;
        if(!root->right) return depth(root->left) + 1;
        return max(depth(root->left), depth(root->right)) + 1;
    }
};