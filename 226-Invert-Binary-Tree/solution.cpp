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
            int len = q.size();
            for(int i = 0; i < len; i++){
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