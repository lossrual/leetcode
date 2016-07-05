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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* p = head;
        for(int i = 0; i < k; i++){
            if(!p)
                return head;
            p = p->next;
        }
        ListNode* newhead = reverse(head, p);
        head->next = reverseKGroup(p, k);
        return newhead;
    }
private:
    ListNode* reverse(ListNode* head, ListNode* tail){
        if(!head) return head;
        ListNode* prev = tail;
        while(head != tail){
            ListNode* nxt =head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }
};