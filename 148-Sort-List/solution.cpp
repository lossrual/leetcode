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
    ListNode* sortList1(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *fast = head, *slow = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        //slow是中间结点，slow->next是下一个结点
        ListNode* mid = slow->next;
        //std::cout << mid->val << std::endl;
        slow->next = nullptr;
        return merge(sortList(head),sortList(mid));
    }
    ListNode* partition(ListNode* start, ListNode* end){
        if(start == end) return nullptr;
        ListNode* p1 = start, *p2 = start->next;
        int key = p1->val;
        while(p2 != end){
            if(key > p2->val){
                p1 = p1->next;
                swap(p1->val, p2->val);
            }
            p2 = p2->next;
        }
        swap(p1->val, start->val);
        return p1;
    }
    void quicksort1(ListNode* start, ListNode* end)
    {
        if(start != end){
            ListNode* pt = partition(start, end);
            quicksort(start, pt);
            quicksort(pt->next, end);
        }
    }
    void quicksort(ListNode* start, ListNode* end)
    {
        while(start != end){
            ListNode* pt = partition(start, end);
            quicksort(start, pt);
            start = pt->next;
            //quicksort(pt->next, end);
        }
    }
    ListNode* sortList(ListNode* head) {
        quicksort(head, nullptr);
        return head;
    }
     
private:
    ListNode* merge(ListNode* l1, ListNode* l2){
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        if(l1->val <= l2->val){
            l1->next = merge(l1->next, l2);
            return l1;
        }else{
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
};