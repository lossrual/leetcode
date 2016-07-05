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
    //1->2->3->null ==> 3->2-1->null,非递归,将当前结点的 next 字段值改成 prev（上一个结点的指针）的值
    ListNode* reverseList(ListNode* head){
        if(!head) return head;
        ListNode* prev = nullptr;
        while(head){
            ListNode* nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }
    //递归
    ListNode* reverseList2(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* newhead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newhead;
    }
};