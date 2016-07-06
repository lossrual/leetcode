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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode* odd = head, *even = head->next;
        ListNode* evenhead = even;
        while(even && even->next){
            odd = odd->next = even->next;
            even = even->next = odd->next;
        }
        odd->next = evenhead;
        return head;
    }
};