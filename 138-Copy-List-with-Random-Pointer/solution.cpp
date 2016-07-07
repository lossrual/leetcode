/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList1(RandomListNode *head) {
        if(head == nullptr) return nullptr;
        RandomListNode* dummy = new RandomListNode(0);
        RandomListNode* cur = dummy;
        unordered_map<RandomListNode*, RandomListNode*> random_map;
        while(head != nullptr){
            RandomListNode* newnode = new RandomListNode(head->label);
            //link newnode to new list
            cur->next = newnode;
            //map old node to newnode
            random_map[head] = newnode;
            //newnode random point to oldnode copy random point
            newnode->random = head->random;
            head = head->next;
            cur = cur->next;
        }
        //再更新random
        cur = dummy->next;
        while(cur){
            if(cur->random){
                cur->random = random_map[cur->random];
            }
            cur = cur->next;
        }
        return dummy->next;
    }
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return head;
        RandomListNode* p1 = head;
        RandomListNode* p2 = new RandomListNode(head->label);
        unordered_map<RandomListNode*, RandomListNode*> mp;
        mp[head] = p2;
        while(p1){
            if(p1->next){
                if(mp.count(p1->next)){
                    p2->next = mp[p1->next];
                }else{
                    p2->next = new RandomListNode(p1->next->label);
                    mp[p1->next] = p2->next;
                }
            }
            if(p1->random){
                if(mp.count(p1->random)){
                    p2->random = mp[p1->random];
                }else{
                    p2->random = new RandomListNode(p1->random->label);
                    mp[p1->random] = p2->random;
                }
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return mp[head];
    }
    
    RandomListNode *copyRandomList2(RandomListNode *head) {
        if(head == nullptr) return nullptr;
        RandomListNode* cur = head;
        //添加重复的节点
        while(cur != nullptr){
            RandomListNode* newnode = new RandomListNode(cur->label);
            //link newnode to new list
            newnode->next = cur->next;
            cur->next = newnode;
            cur = cur->next->next;
        }
        //更改random指针
        cur = head;
        while(cur != nullptr){
            if(cur->random != nullptr){
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        //split lists
        cur = head;
        RandomListNode* newhead = head->next;
        while(cur != nullptr){
            RandomListNode* newnode = cur->next;
            cur->next = cur->next->next;
            cur = cur->next;
            if(newnode->next != nullptr){
                newnode->next = newnode->next->next;
            }
        }
        return newhead;
    }
};