#include<bits/stdc++.h>
class Solution {
    int dp[10001];
    int fun(vector<int> &v,int amount){
        if(amount==0){
            return 0;
        }
        if(dp[amount]!=-1) return dp[amount];
        int ans = 1e9;
        for(auto x:v){
            if(amount-x>=0){
                ans = min(ans,1+fun(v,amount-x));
            }
        }
        return dp[amount] = ans;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof dp);
        int ans = fun(coins,amount);
        return ans==1e9?-1:ans;
    }
};
