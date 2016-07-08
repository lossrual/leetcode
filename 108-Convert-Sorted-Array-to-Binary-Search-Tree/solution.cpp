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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return nullptr;
        return convert(nums, 0, nums.size());
    }
    TreeNode* convert(vector<int>& nums, int begin, int end){
        if(begin >= end) return nullptr;
        int mid = begin + (end - begin) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = convert(nums, begin, mid);
        root->right = convert(nums, mid + 1, end);
        return root;
    }    
};