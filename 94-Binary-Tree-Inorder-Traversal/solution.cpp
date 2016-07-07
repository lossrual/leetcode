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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        //res.push_back(root);
        inorder(root, res);
        return res;
    }
    
    vector<int> inorderTraversal1(TreeNode* root) {
        vector<int> res;
        //TreeNode* tmp = root, *pre;
        if(!root) return res;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(!s.empty() || cur){
            if(cur){
                s.push(cur);
                cur = cur->left;
            }else{
                TreeNode* p = s.top();
                res.push_back(p->val);
                s.pop();
                cur = p->right;
            }
        }
        return res;
    }
private:
    void inorder(TreeNode* root, vector<int>& res){
        if(!root) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    
};