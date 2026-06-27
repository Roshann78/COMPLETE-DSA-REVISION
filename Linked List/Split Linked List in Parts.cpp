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
    ListNode* pass(ListNode*head,int c){
        ListNode*temp=head;
        for(int i=1;i<c;i++){
            temp=temp->next;
        }
        return temp;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans;

        int n=sze(head);

        int c1=n/k;
        int c2=n%k;

        int c=0;
        ListNode*cur=head;

        for(int i=0;i<k;i++){

            if(c1){
                ans.push_back(cur);
                cur=pass(cur,c1+(c2!=0));
                ListNode*temp=cur->next;
                cur->next=nullptr;
                cur=temp;
                c2-=(c2!=0);
                continue;
            }
            if(c2){
                ans.push_back(cur);
                ListNode*temp=cur->next;
                cur->next=nullptr;
                cur=temp;
                c2--;
            }else{
                ans.push_back(nullptr);
            }
        }
        return ans;
    }
};