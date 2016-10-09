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
//树的最大深度
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        //int left = 0, right = 0;
        //if(!root->left) return maxDepth(root->right) + 1;
        //if(!root->right) return maxDepth(root->left) + 1;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};