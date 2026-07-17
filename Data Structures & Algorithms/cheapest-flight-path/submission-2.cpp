class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> v[n];
        for(auto x:flights){
            v[x[0]].push_back({x[1],x[2]});
        }

        priority_queue<pair<int,pair<int,int>>> pq;
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        pq.push({0,{src,0}});
        while(!pq.empty()){
            int cost = pq.top().first;
            int nxt = pq.top().second.first;
            int stop = pq.top().second.second;
            // cout<<nxt<<" "<<stop<<" "<<cost<<endl;
            pq.pop();
            if(stop>k) continue;

            for(auto [x,c]:v[nxt]){
                if( dist[x] > dist[nxt] + c and stop<=k){
                    dist[x] = dist[nxt] + c;
                    pq.push({dist[x],{x,stop+1}});
                }
            }
        }

        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};
