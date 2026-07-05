/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 class cmp {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};
class Solution {

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp>pq;

        ListNode dummy(0);
        ListNode*temp=&dummy;

        for(auto i:lists){
            if(i){
                pq.push(i);
            }
        }

        while(!pq.empty()){

            ListNode*cur=pq.top();
            pq.pop();

            temp->next=cur;
            temp=temp->next;
            cur=cur->next;
            if(cur){
                pq.push(cur);
            }
        }

        return dummy.next;

    }
};