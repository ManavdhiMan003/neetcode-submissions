class dsu{
    vector<int> par;
    public:
    dsu(int n){
        for(int i=0;i<=n;i++) par.push_back(i);
    }
    int find(int a){
        if(par[a]==a) return a;
        return par[a] = find(par[a]);
    }
    void join(int a,int b){
        int pa = find(a);
        int pb = find(b);
        par[pa] = pb;
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
