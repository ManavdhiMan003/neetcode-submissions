class Solution {
    bool fun(vector<int> v[],unordered_set<int> &vist,int x,int par){
        if(vist.count(x)) return false;
        vist.insert(x);
        for(auto i:v[x]){
            if(i==par){
                continue;
            }
            if(fun(v,vist,i,x)==false) return false;
        }
        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()>n-1) return false;
        vector<int> v[n];
        for(auto x:edges){
            v[x[0]].push_back(x[1]);
            v[x[1]].push_back(x[0]);
        }
        unordered_set<int> vist;
        if(!fun(v,vist,0,-1)) return false;
        
        return vist.size()==n;
    }
};
