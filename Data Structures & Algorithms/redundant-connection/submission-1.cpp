class dsu{
    vector<int> par,rank;
    public:
    dsu(int n){
        par.resize(n+1);
        rank.resize(n+1);

        for(int i=1;i<=n;i++){
            par[i] = i;
            rank[i] = 0;
        }
    }
    int find(int a){
        if(par[a]==a) return a;
        return par[a] = find(par[a]);
    }
    void join(int a,int b){
        int pa = find(a);
        int pb = find(b);
        if(rank[pa]>rank[pb]){
            par[pa] = pb;
        }else if(rank[pa]<rank[pb]){
            par[pb] = pb;
        }else{
            par[pa] = pb;
            rank[pa]++;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& v) {
        int n = v.size();
        dsu st(n);
        for(auto x:v){
            if(st.find(x[0])==st.find(x[1])) return {x[0],x[1]};
            st.join(x[0],x[1]);
        }
        return {};
    }
};
