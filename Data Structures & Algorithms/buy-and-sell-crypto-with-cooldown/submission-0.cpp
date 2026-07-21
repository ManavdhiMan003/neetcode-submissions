#include<bits/stdc++.h>
class Solution {
    int dp[5005][2];
    int fun(vector<int> &v,int x,int trans){
        if(x>=v.size()) return 0;
        if(dp[x][trans]!=-1) return dp[x][trans];
        int cool = fun(v,x+1,trans);
        if(trans==0){
            return dp[x][trans] = max(cool,fun(v,x+1,1)-v[x]);
        }else return dp[x][trans] = max(cool,fun(v,x+2,0)+v[x]);
    }
public:
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        return fun(prices,0,0);
    }
};

