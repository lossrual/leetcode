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
    int minDepth(TreeNode* root) {
        return depth(root);
    }
private:
    int depth(TreeNode* root){
        if(!root) return 0;
        if(!root->left) return depth(root->right) + 1;
        if(!root->right) return depth(root->left) + 1;
         return min(depth(root->right), depth(root->left)) + 1;
    }
};