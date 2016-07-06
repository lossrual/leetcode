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
    bool isPalindrome1(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* slow = head, *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        ListNode* newhead = reverse(mid);
        while(head && newhead){
            if(head->val == newhead->val){
                head = head->next;
                newhead = newhead->next;
            }else
                return false;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow;
        //slow->next = nullptr;
        ListNode* newhead = reverse(mid);
        while(head && newhead){
            if(head->val == newhead->val){
                head = head->next;
                newhead = newhead->next;
            }else
                return false;
        }
        return true;
    }
private:
    ListNode* reverse(ListNode* head){
        ListNode* pre = nullptr;
        if(!head) return head;
        while(head){
            ListNode* nxt = head->next;
            head->next = pre;
            pre = head;
            head = nxt;
        }
        return pre;
    }
};