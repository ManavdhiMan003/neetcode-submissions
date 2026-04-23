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
private:
    ListNode* reverse(ListNode* node){
    ListNode* cur=node;
    ListNode* prev=nullptr;
    ListNode* nxt = node->next;
    while(cur){
        nxt = cur->next;
        cur->next=prev;
        prev=cur;
        cur=nxt;
    }
    return prev;
}
public:
    void reorderList(ListNode* head) {
        int n=0;
        ListNode* temp=head;
        while(temp!=nullptr and temp->next!=nullptr){
            temp=temp->next->next;
            n+=2;
        }
        if(temp!=nullptr) n++;
        if(n<=2) return;

        int mid = (n+1)/2;
        temp=head;
        int i=1;
        while(i!=mid){
            temp = temp->next;
            i++;
        }

        ListNode* second = temp->next;
        temp->next=nullptr;
        ListNode* first=head;

        second = reverse(second);

        temp=head;
        i=0;
        while(i!=n-1){
            if(i%2){
                second=temp->next;
                temp->next = first;
            }else{
                first = temp->next;
                temp->next = second;
            }
            temp = temp->next;
            // cout<<temp->val<<" ";
            i++;
        }    
        // if(i!=n) temp->next=first;
        // return;
    }
};


