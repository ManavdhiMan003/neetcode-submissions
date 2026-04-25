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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int car=0;
        ListNode* ret = new ListNode(0);
        ListNode* it=ret;
        while(l1!=nullptr and l2!=nullptr){
            it->val = (l1->val+l2->val+car)%10;
            car=(l1->val+l2->val+car)/10;
            l1=l1->next;
            l2=l2->next;
            if(l1!=nullptr or l2!=nullptr){
                it->next=new ListNode();
                it=it->next;
            }
        }
        while(l1!=nullptr){
            it->val = (l1->val+car)%10;
            car=(l1->val+car)/10;
            l1=l1->next;
            if(l1){
                it->next=new ListNode();
                it=it->next;
            }
        }
        while(l2!=nullptr){
            it->val = (l2->val+car)%10;
            car=(l2->val+car)/10;
            l2=l2->next;
            if(l2){
                it->next=new ListNode();
                it=it->next;
            } 
        }
        if(car!=0){
            it->next=new ListNode(car);
        }
        return ret;
    }
};
