class Solution {
    vector<int> dp;
    int fun(vector<int> &v,int x){
        if(x>=v.size()) return 0;
        if(dp[x]!=-1) return dp[x];
        return dp[x] = max(fun(v,x+1),fun(v,x+2)+v[x]);
    }
public:
    int rob(vector<int>& v) {
        int n = v.size();
        dp.resize(n,-1);

        return fun(v,0);
    }
};


// x -> skip x+1, rob x+2
