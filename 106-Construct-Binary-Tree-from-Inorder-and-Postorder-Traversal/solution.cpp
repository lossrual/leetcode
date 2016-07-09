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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(postorder, inorder, 0, postorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode* helper(vector<int>& postorder, vector<int>& inorder, int pl, int pr, int il, int ir){
        if(pl > pr) return nullptr;
        TreeNode* cur = new TreeNode(postorder[pr]);
        int pos = 0;
        for(int i = il; i <= ir; i++){
            if(cur->val == inorder[i]){
                pos = i;
                break;
            }
        }
        cur->left = helper(postorder, inorder, pl, pl + pos - il - 1, il, pos - 1);
        cur->right = helper(postorder, inorder, pr - ir + pos, pr - 1, pos + 1, ir);
        return cur;
    }
};