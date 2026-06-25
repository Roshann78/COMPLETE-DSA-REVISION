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

    ListNode* rev(ListNode*head,ListNode*temp,ListNode*end){

        ListNode*prev=temp;
        ListNode*cur=head;

        while(cur){
            int f=0;
            if(cur==end){
                f=1;
            }
            ListNode*temp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
            if(f){
                break;
            }
        }

        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int c=0;
        ListNode*temp=head;
        ListNode*prev=head;
        ListNode*prev1=nullptr;

        ListNode*ans=head;
        for(int i=1;i<k;i++){
            ans=ans->next;
            if(!ans){
                return head;
            }
        }
        while(temp){
            c++;
            if(c==k){
                rev(prev,temp->next,temp);
            
                if(prev1!=nullptr){
                    prev1->next=temp;
                }
                prev1=prev;
                prev=prev->next;
                temp=prev;
                c=0;
            }else{
                temp=temp->next;
            }
        }
        return ans;
    }
};