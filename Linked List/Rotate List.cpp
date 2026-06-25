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
class Solution {
public:
    int sze(ListNode*head){
        ListNode*temp=head;
        int ans=0;
        while(temp){
            ans++;
            temp=temp->next;
        }
        return ans;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        
        int sz=sze(head);
        if(!head || !(head->next)){
            return head;
        }
        k%=sz;
        k=sz-k;
        ListNode*temp=head;
        ListNode*tail=head;

        while(tail->next){
            tail=tail->next;
        }

        for(int i=1;i<k;i++){
            temp=temp->next;
        }

        ListNode*ans=temp->next;
        if(!ans){
            return head;
        }
        temp->next=nullptr;
        tail->next=head;

        return ans;
    }
};