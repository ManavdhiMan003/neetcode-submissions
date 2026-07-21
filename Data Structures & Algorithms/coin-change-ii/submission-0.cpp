#include<bits/stdc++.h>
class Solution {
    int dp[105][5005];
    int fun(int amt,vector<int> &v,int x){
        if(amt==0) return 1;
        if(x>=v.size() or amt<0) return 0;
        if(dp[x][amt]!=-1) return dp[x][amt];
        return dp[x][amt] = fun(amt-v[x],v,x) + fun(amt,v,x+1);
    }
public:
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof dp);
        return fun(amount,coins,0);
    }
};
