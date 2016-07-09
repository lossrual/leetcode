/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        TreeLinkNode* cur = nullptr;
        TreeLinkNode* head = root;
        TreeLinkNode* pre = nullptr;
        while(head){
            cur = head;
            head = nullptr, pre = nullptr;
            while(cur){
                if(cur->left){
                    if(pre){
                        pre->next = cur->left;
                    }else{
                        head = cur->left;
                    }
                    pre = cur->left;
                }
                if(cur->right){
                    if(pre){
                        pre->next = cur->right;
                    }else{
                        head = cur->right;
                    }
                    pre = cur->right;
                }
                cur = cur->next;   
            }
        }
    }
};