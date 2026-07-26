class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto x:stones) pq.push(x);
        
        while(!pq.empty() and pq.size()>=2){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if(x>y){
                pq.push(x-y);
            }
        }
        return pq.size()==0?0:pq.top();
    }
};
