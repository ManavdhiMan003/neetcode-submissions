class Solution {
    struct data{
        int a,b;   
    };
    struct cmp{
        bool operator()(data d1 , data d2){
            return d1.a>d2.a;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        priority_queue<data, vector<data>, cmp> pq;
        vector<int> ans;
        for(auto x:nums){
            mp[x]++;
        }
        for(auto x:mp){
            pq.push({x.second,x.first});
            if(pq.size()>k) pq.pop();
        }
        while(k--){
            ans.push_back(pq.top().b);
            pq.pop();
        }

        return ans;
    }
};
