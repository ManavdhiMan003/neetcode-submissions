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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list2==nullptr) return list1;
        if(list1==nullptr) return list2;
        ListNode* head = (list1->val>=list2->val)?list2:list1;

        ListNode* curr=nullptr;
        while(list1!=nullptr and list2!=nullptr){
            if(list1->val>=list2->val){
                if(curr==nullptr) curr=list2;
                else{
                    curr->next = list2;
                    curr=curr->next;
                }
                list2 = list2->next;
            }else{
                if(curr==nullptr) curr=list1;
                else{
                    curr->next = list1;
                    curr=curr->next;
                }
                list1 = list1->next;
            }
            // cout<<curr->val<<" ";
        }
        if(list1!=nullptr){
            curr->next=list1;
        }else if(list2!=nullptr)curr->next = list2;
        return head;

    }
};
