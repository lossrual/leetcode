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
    void reorderList1(ListNode* head) {
        if(!head) return;
        ListNode* slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = slow->next;
        slow->next = nullptr;
        ListNode* pre = nullptr;
        while(head2){
            ListNode* nxt = head2->next;
            head2->next = pre;
            pre = head2;
            head2 = nxt;
        }
        head2 = pre;
        while(head){
            ListNode* cur = head->next;
            head = head->next = head2;
            head2 = cur;
        }
    }
    void reorderList(ListNode* head) {
        if(!head) return;
        ListNode* slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = slow;
        //slow->next = nullptr;
        ListNode* pre = nullptr;
        while(head2){
            ListNode* nxt = head2->next;
            head2->next = pre;
            pre = head2;
            head2 = nxt;
        }
        head2 = pre;
        while(head){
            ListNode* cur = head->next;
            head = head->next = head2;
            head2 = cur;
        }
    }
};