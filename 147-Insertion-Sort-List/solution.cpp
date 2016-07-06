/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //O(n^2) O(1)
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return head;
        ListNode* dummy = new ListNode(0);
        ListNode* pre, *cur, *nxt;
        pre = dummy, cur = head;
        while(cur){
            pre = dummy;//每次pre都要指向开头处
            nxt = cur->next;
            //找到要插入的地方
            while(pre->next && pre->next->val <= cur->val){
                pre = pre->next;
            }
            cur->next = pre->next;
            pre->next = cur;
            cur = nxt;
        }
        return dummy->next;
    }
};