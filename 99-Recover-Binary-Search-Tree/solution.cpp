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
    TreeNode* pre = new TreeNode(INT_MIN), *first = nullptr, *second = nullptr;
public:
    void recoverTree(TreeNode* root) {
        if(!root) return;
        //vector<int> vs = InorderTraversal(root);
        InorderTraversal(root);
        std::swap(first->val, second->val);
    }
    void InorderTraversal(TreeNode* cur){
        if(!cur) return;
        InorderTraversal(cur->left);
        if(first == nullptr && pre->val >= cur->val) first = pre;
        if(first != nullptr && pre->val >= cur->val) second = cur;
        pre = cur;
        InorderTraversal(cur->right);
    }
    /*
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
    */
};