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
        if(root){
            root->left = invertTree(root->left);
            root->right = invertTree(root->right);
            swap(root->left, root->right);
        }
        return root;
    }
    TreeNode* invertTree(TreeNode* root){
        if(!root) return root;
        queue<TreeNode*> q;
        TreeNode* cur = root;
        q.push(root);
        while(!q.empty()){
            cur = q.front();
            q.pop();
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
            swap(cur->left, cur->right);
        }
        return root;
    }
};