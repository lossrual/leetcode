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
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode* cur = root;
        while(cur){
                //std:: cout << cur->val << '\n';
            if(cur->left){
                //std:: cout << cur->val << '\n';
                TreeNode* nxt = cur->left;
                //std::cout << nxt->val << '\n';
                while(nxt->right){
                    nxt = nxt->right;
                }
                //std::cout << nxt->val << ' ' << cur->right->val << '\n';
                
                nxt->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right;
        }
    }
    /*
    vector<int> PreorderTraversal(TreeNode* root){
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(!s.empty() || cur){
            if(cur){
                s.push(cur);
                res.push_back(cur->val);
                cur = cur->left;
            }else{
                cur = s.top();
                s.pop();
                cur = cur->right;
            }
        }
        return res;
    }
    */
};