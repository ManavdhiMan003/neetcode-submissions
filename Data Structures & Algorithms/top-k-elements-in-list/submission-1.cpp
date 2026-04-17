class Solution {
    struct data{
        int a,b;   
    };
    struct cmp{
        bool operator()(data d1 , data d2){
            return d1.a<d2.a;
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
        }
        while(k--){
            // cout<<pq.top().a<<" "<<
            ans.push_back(pq.top().b);
            pq.pop();
        }
        // for(auto x:mp) if(x.second>=k) ans.push_back(x.first);
        return ans;
    }
};
