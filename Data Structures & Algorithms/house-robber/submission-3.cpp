class Solution {
    // vector<int> dp;
    // int fun(vector<int> &v,int x){
    //     if(x>=v.size()) return 0;
    //     if(dp[x]!=-1) return dp[x];
    //     return dp[x] = max(fun(v,x+1),fun(v,x+2)+v[x]);
    // }
public:
    int rob(vector<int>& v) {
        int n = v.size();
        if(n==0) return 0;
        if(n==1) return v[0];
        // dp.resize(n,-1);
        // dp[0] = v[0];
        // dp[1] = max(v[0],v[1]);
        int a=v[0],b=max(v[0],v[1]);
        for(int i=2;i<n;i++){
            int temp = max(b,v[i]+a);
            a = b;
            b = temp;
        }
        return b;
    }
};


// x -> skip x+1, rob x+2
