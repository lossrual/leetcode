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
    TreeNode* invertTree1(TreeNode* root) {
        if(!root) return root;
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            for(int i = 0; i < q.size(); i++) {
                auto node = q.front();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                swap(node->left, node->right);
                q.pop();
            }
        }
        return root;
    }
};