/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p = dummy;
        //ListNode* cur = head;
        while(p->next && p->next->next){
            if(p->next->val == p->next->next->val){
                int k = p->next->val;
                while(p->next && p->next->val == k)
                    p->next = p->next->next;
            }else{
                p = p->next;
            }
        }
        return dummy->next;
    }
};