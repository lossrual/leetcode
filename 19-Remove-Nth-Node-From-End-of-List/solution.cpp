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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* p = head;
        int count = 0;
        while(p){
            ++count;
            p = p->next;
        }
        p = head;
        int k = count - n;
        if(k == 0)
            return nullptr;
        while(k--){
            p = p->next;
        }
        //ListNode* cur = p->next;
        //ListNode* nxt = cur->next;
        //p->next = nxt;
        p->next = p->next->next;
        return head;
    }
};