class Solution {
    struct dsu{
        vector<int> parent;
        vector<int> rank;
        public:
        dsu(int n){
            parent.assign(n+1,-1);
            rank.assign(n+1,0);
            for(int i=0;i<=n;i++){
                parent[i] = i;
            }
        }
        int find(int a){
            if(parent[a]==a) return a;
            return parent[a] = find(parent[a]);
        }
        bool join(int a, int b){
            auto ulpa = find(a);
            auto ulpb = find(b);
            if(ulpa==ulpb) return false;
            if(rank[ulpa] > rank[ulpb]){
                parent[ulpb] = ulpa;
            }else if(rank[ulpa] < rank[ulpb]){
                parent[ulpa] = ulpb;
            }else{
                parent[ulpa] = ulpb;
                rank[ulpb]++;
            }
            return true;
        }

    };
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<array<int,3>> v;
        int n = points.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                v.push_back({dist,i,j});
            }
        }
        dsu dsu(n);
        sort(v.begin(),v.end());
        int ans = 0;
        for(auto x:v){
            if(dsu.join(x[1],x[2])){
                ans += x[0];
            }
        }
        return ans;
    }
};
