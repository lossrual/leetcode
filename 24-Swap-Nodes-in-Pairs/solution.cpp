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
    ListNode* swapPairs1(ListNode* head) {
        ListNode dummy(0);
        ListNode* p = head;
        ListNode* dd = &dummy;
        dummy.next = head;
        while(p && p->next){
            //ListNode* cur = p->next;
            ListNode* nxt = p->next->next;
            dd->next = p->next;
            dd->next->next = p;
            p->next = nxt;
            dd = p;
            p = nxt;
        }
        return dummy.next;
    }
    ListNode* swapPairs(ListNode* head) {
       if(!head || !head->next) return head;
       ListNode* nxt = head->next;
       head->next = swapPairs(head->next->next);
       nxt->next = head;
       return nxt;
    }
};