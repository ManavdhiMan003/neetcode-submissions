#include<bits/stdc++.h>
class Solution {
    int dp[105];
    int fun(vector<int> &v,int n){
        if(v.size()<=n) return 0;
        if(dp[n]!=-1) return dp[n];
        // if(dp[n]!=-1) return dp[n];
        // cout<<v[n]<<" "<<n<<endl;
        return dp[n] = min(fun(v,n+2),fun(v,n+1))+v[n];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memset(dp,-1,sizeof dp);
        // vector<int> dp(n+1,-1);
        // vector<int> dp2(n+1,-1);
        // fun(cost,0,dp);
        // fun(cost,1,dp2);

        // for(int i=0;i<=n;i++) cout<<dp[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<=n;i++) cout<<dp2[i]<<" ";
        // cout<<endl;
        // return min(dp[n-1],dp2[n-1]);
        return min(fun(cost,0),fun(cost,1));
    }
};
