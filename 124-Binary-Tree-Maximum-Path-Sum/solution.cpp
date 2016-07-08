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
/*
    int maxPathSum(TreeNode* root) {
        //if(!root) return 0;
        int path = INT_MIN;
        path = helper(root, path);
        return path;
        
        if(!root->left && !root->right) return root->val;
        vector<int> left; vector<int> right;
        int path = root->left->val;
        helper(root->left, left, path);
        path = root->right->val;
        helper(root->right, right, path);
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        return left[left.size() - 1] + right[right.size() - 1] + root->val;
        
        
    }
    int helper(TreeNode* root, int path){
        //int l = 0, r = 0;
        if(!root) return 0;
        int l = max(0, helper(root->left, path));
        int r = max(0, helper(root->right, path));
        path = max(path, l + r + root->val);
        return max(l, r) + root->val;
    }
*/
    int maxPathSum(TreeNode* root) {
        int maxpath = INT_MIN;
        //vector<int> res;
        int res =  dfs(root, maxpath);
        if(res > maxpath)
            maxpath = res;
        return maxpath;
        //sort(res.begin(), res.end());
        //return res[res.size() - 1];
        //return maxpath;
    }
    int dfs(TreeNode* root, int& maxpath){
        if(!root) return 0;
        //if(!root->left && !root->right){
        //    res.push_back(maxpath);
        //    return res;
        //}
        int l = max(0, dfs(root->left, maxpath));
        int r = max(0, dfs(root->right, maxpath));
        maxpath = max(maxpath, l + r + root->val);
        return max(l, r)+ root->val;
        //int k =  max(l, r) + root->val;
    }

};