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
    //链表有环,求环的入口
    ListNode *detectCycle(ListNode *head) {
        if(!head) return head;
        ListNode* slow = head, *fast = head;
        while(fast&& fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                ListNode* slow2= head;
                while(slow != slow2) {
                    slow = slow->next;
                    slow2 = slow2->next;
                }
                return slow2;
            }
        }
        return nullptr;
    }
};