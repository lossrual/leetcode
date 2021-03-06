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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode*> q;
        TreeNode* cur = root;
        q.push(root);
        while(!q.empty()){
            vector<int> path;
            int len = q.size();
            for(int i = 0; i < len; i++){
                auto node = q.front();
                path.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                q.pop();
            }
            res.push_back(path[path.size() - 1]);
        }
        return res;
    }
};