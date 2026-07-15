class Solution {
    struct data{
        int dst,time;
    };
    struct cmp{
        bool operator()(data &a,data &b){
            return a.time<b.time;
        }
    };
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        k--;
        vector<data> v[n];
        for(auto x:times){
            v[x[0]-1].push_back({x[1]-1,x[2]});
        }  

        vector<int> vist(n,INT_MAX);
        priority_queue<data,vector<data>, cmp> pq;
        pq.push({k,0});
        vist[k]=0;
        while(!pq.empty()){
            int nxt = pq.top().dst;
            int time = pq.top().time;
            pq.pop();
            for(auto x:v[nxt]){
                if(vist[x.dst] > vist[nxt]+x.time){
                    vist[x.dst] = vist[nxt]+x.time;
                    pq.push(x);
                }
            }
        }
        // for(auto x:vist) cout<<x<<" ";
        // cout<<endl;
        int ans = 0;
        for(auto x:vist) ans = max(ans,x);
        return ans==INT_MAX?-1:ans;
    }
};
