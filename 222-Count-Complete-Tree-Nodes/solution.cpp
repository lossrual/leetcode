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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int hl = 0, hr = 0;
        TreeNode* p = root;
        while(p){
            ++hl;
            p = p->left;
        }
        p = root;
        while(p){
            ++hr;
            p = p->right;
        }
        if(hl == hr) return pow(2, hl) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};