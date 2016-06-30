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
        TreeNode* tmp = root, *pre;
        if(!root) return res;
        while(tmp){
            if(!tmp->left){
                res.push_back(tmp->val);
                tmp = tmp->right;
            }
            else{
                pre = tmp->left;
                while(pre->right && pre->right != tmp)
                    pre = pre->right;
                if(!pre->right){
                    pre->right = tmp;
                    tmp = tmp->left;
                }
                else{
                    res.push_back(tmp->val);
                    pre->right = nullptr;
                    tmp = tmp->right;
                }
            }
        }
        
    }
};