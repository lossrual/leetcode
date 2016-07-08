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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vs = InorderTraversal(root);
        return vs[k - 1];
    }
    vector<int> InorderTraversal(TreeNode* root){
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(!s.empty() || cur){
            if(cur){
                s.push(cur);
                cur = cur->left;
            }else{
                cur = s.top();
                s.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
};