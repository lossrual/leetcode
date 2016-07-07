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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return generate(1, n);
    }
    vector<TreeNode*> generate(int start, int end){
        vector<TreeNode*> res;
        if(start > end){
            res.push_back(nullptr);
            return res;
        }
        for(int i = start; i <= end; i++){
            auto l = generate(start, i - 1);
            auto r = generate(i + 1, end);
            for(int m = 0; m < l.size(); m++){
                for(int k = 0; k < r.size(); k++){
                    TreeNode* node = new TreeNode(i);
                    node->left = l[m];
                    node->right = r[k];
                    res.push_back(node);
                }
            }
        }
        return res;
    }
};