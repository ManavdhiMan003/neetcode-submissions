class Solution {
    struct data{
        int dist,x1,y1,x2,y2;
    };
    class DSU{
        
        public:
        map<pair<int,int>,pair<int,int>> par;
        map<pair<int,int>,int> rank;
        DSU(vector<pair<int,int>> v){
            par.clear();
            rank.clear();
            for(auto x:v){
                par[x] = x;
                rank[x] = 0;
            }
        }
        pair<int,int> find(pair<int,int> a){
            if(par[a]==a) return a;
            return par[a] = find(par[a]);
        }
        void join(pair<int,int> a,pair<int,int> b){
            auto pa = find(a);
            auto pb = find(b);
            if(rank[pa]>rank[pb]){
                par[pa]=pb;
            }else if(rank[pa]<rank[pb]){
                par[pb]=pa;
            }else{
                par[pa] = pb;
                rank[pa]++;
            }
        }
    };
    struct cmp{
        bool operator()(data &a,data &b){
            return a.dist>b.dist;
        }
    };
public:
    int minCostConnectPoints(vector<vector<int>>& v) {
        int n = v.size();
        priority_queue<data,vector<data>,cmp> pq;
        vector<pair<int,int>> par;
        for(int i=0;i<n;i++){
            int x1 = v[i][0];
            int y1 = v[i][1];
            par.push_back({x1,y1});
            for(int j=i+1;j<n;j++){
                int x2 = v[j][0];
                int y2 = v[j][1];
                pq.push({abs(x1-x2)+abs(y1-y2),x1,y1,x2,y2});
            }
        }
        
        DSU st(par);
        for(auto x:st.par){
            cout<<x.first.first<<" "<<x.first.second<<" "<<x.second.first<<" "<<x.second.second<<endl;
        }
        int ans = 0;
        while(!pq.empty()){
            int dist = pq.top().dist;
            int x1 = pq.top().x1;
            int x2 = pq.top().x2;
            int y1 = pq.top().y1;
            int y2 = pq.top().y2;
            pq.pop();
            // cout<<dist<<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
            if(st.find({x1,y1})!=st.find({x2,y2})){
                st.join({x1,y1},{x2,y2});
                ans+=dist;
            }
        }
        return ans;
    }
};
