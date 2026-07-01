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
    ListNode* removeNodes(ListNode* head) {
        if(!head){
            return head;
        }
        ListNode*revhead=rev(head);
        int mx=revhead->val;
        ListNode*cur=revhead->next;
        ListNode*prev=revhead;
        while(cur){
            while(cur && (cur->val)<mx){
                cur=cur->next;
            }
            prev->next=cur;
            if(!cur){
                break;
            }
            mx=max(mx,cur->val);
            prev=cur;
            cur=cur->next;
        }
        return rev(revhead);
    }
};