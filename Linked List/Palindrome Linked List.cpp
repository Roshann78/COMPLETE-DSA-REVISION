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
    ListNode*rev(ListNode*head){

        ListNode*prev=nullptr;
        ListNode*cur=head;

        while(cur){
            ListNode*temp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
        }

        return prev;

    }
    bool isPalindrome(ListNode* head) {
        
        ListNode*slow=head;
        ListNode*fast=head;

        while(fast && fast->next){

            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode*nxt;

        if(fast){
            nxt=rev(slow->next);
        }else{
            nxt=rev(slow);
        }

        ListNode*l1=head;
        ListNode*l2=nxt;

        while(l2){
            if((l1->val) != (l2->val)){
                return false;
            }
            l1=l1->next;
            l2=l2->next;
        }

        return true;

    }
};