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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // if(lists.size()==0) return nullptr;
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq;
        for(auto x:lists){
            if(x==nullptr) continue;
            pq.push({x->val,x});
        }
        if(pq.size()==0) return nullptr;
        ListNode* head = pq.top().second;
        ListNode* it=head;
        cout<<head->val<<endl;
        while(!pq.empty()){
            ListNode* temp = pq.top().second;
            pq.pop();
            cout<<temp->val<<" ";
            if(temp->next) pq.push({temp->next->val,temp->next});
            it->next=temp;
            it=it->next;
        }
        return head;
    }
};
