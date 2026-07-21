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
    int change(int amt, vector<int>& v) {
        int n = v.size();
        memset(dp,0,sizeof dp);
        sort(v.begin(),v.end());

        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int i=n-1;i>=0;i--){
            for(int a=0;a<=amt;a++){
                if(a>=v[i]){
                    dp[i][a] = dp[i+1][a];
                    dp[i][a] += dp[i][a-v[i]];
                }
            }
        }
        return dp[0][amt];
    }
};
