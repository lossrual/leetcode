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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
private:
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir){
        if(pl > pr) return nullptr;
        TreeNode* cur = new TreeNode(preorder[pl]);
        int pos = 0;
        for(int i = il; i <= ir; i++){
            if(cur->val == inorder[i]) {
                pos = i; break;
            }
        }
        cur->left = dfs(preorder, inorder, pl + 1, pl + pos - il, il, pos - 1);
        cur->right = dfs(preorder, inorder, pr - ir + pos + 1, pr, pos + 1, ir);
        return cur;
    }
};