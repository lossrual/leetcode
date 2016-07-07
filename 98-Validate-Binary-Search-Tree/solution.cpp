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
/* 非递归
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        vector<int> vs = InorderTraversal(root);
        for(int i = 0; i < vs.size() - 1; i++){
            //std::cout << vs[i] << ' ';
            if(vs[i] >= vs[i + 1])
                return false;
        }
        return true;
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
    */
    //递归
    bool isValidBST(TreeNode* root) {
        return Valid(root, LONG_MIN, LONG_MAX);
    }
    bool Valid(TreeNode* root, long lower, long upper){
        if(!root) return true;
        if(root->val >= upper || root->val <= lower) return false;
        return Valid(root->left, lower, root->val) && Valid(root->right, root->val, upper);
    }
    
};