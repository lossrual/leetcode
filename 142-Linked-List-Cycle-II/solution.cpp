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
    ListNode *detectCycle(ListNode *head) {
        if(!head) return head;
        ListNode* slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                ListNode* slow2 = fast;
                while(slow2　!= slow){
                    slow = slow->next;
                    slow2 = slow2->next;
                }
            }
        }
        return slow;
    }
};