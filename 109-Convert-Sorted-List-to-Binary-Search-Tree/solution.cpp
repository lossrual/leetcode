/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST1(ListNode* head) {
        return sortedListToBST(head, nullptr);
    }
    TreeNode* sortedListToBST(ListNode* head){
        if(!head) return nullptr;
        //if(!head->next) return new TreeNode(head->val);
        ListNode* slow = head, *fast = head, *pre = nullptr;
        while(fast && fast->next){
            fast = fast->next->next;
            pre = slow;//pre是中间结点前面的结点
            slow = slow->next;
        }
        //std::cout << slow->val << std::endl;
        TreeNode* root = new TreeNode(slow->val);
        //ListNode* rh = slow->next;
        if(pre != nullptr) 
            pre->next = nullptr;
        else 
            head = nullptr;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
private:
    TreeNode* sortedListToBST(ListNode* head, ListNode* tail){
        if(head == tail) return nullptr;
        ListNode* slow = head, *fast = head;
        while(fast != tail && fast->next != tail){
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* root = new TreeNode(slow->val); 
        root->left = sortedListToBST(head, slow);
        root->right = sortedListToBST(slow->next, tail);
        return root;
        
    }
};