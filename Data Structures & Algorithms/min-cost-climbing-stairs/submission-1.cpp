#include<bits/stdc++.h>
class Solution {
    int dp[105];
    int fun(vector<int> &v,int n){
        if(v.size()<=n) return 0;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = min(fun(v,n+2),fun(v,n+1))+v[n];
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memset(dp,-1,sizeof dp);
        return min(fun(cost,0),fun(cost,1));
    }
};
