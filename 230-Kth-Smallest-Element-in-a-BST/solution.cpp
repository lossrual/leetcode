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
    int kthSmallest1(TreeNode* root, int k) {
        vector<int> vs = InorderTraversal(root);
        return vs[k - 1];
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = CountNode(root->left);
        if(k <= count){
            return kthSmallest(root->left, k);
        }else if(k > count + 1){
            return kthSmallest(root->right, k - count - 1);
        }else
            return root->val;
    }
private:
    int CountNode(TreeNode* root){
        if(!root) return 0;
        return CountNode(root->left) + CountNode(root->right) + 1;
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