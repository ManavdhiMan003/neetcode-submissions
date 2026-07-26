class KthLargest {
    priority_queue<int,vector<int>,greater<int>> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        while(!pq.empty()) pq.pop();
        this->k = k;
        for(auto x:nums){
            pq.push(x);
            if(pq.size()>k) pq.pop();
        }

    }
    
    int add(int x) {
        pq.push(x);
        if(pq.size()>k) pq.pop();
        return pq.top();
    }
};
