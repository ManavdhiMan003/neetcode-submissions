#include <cstring>

class Solution {
    int dp[50];
    int fun(int n){
        if(n==0) return 1;
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = fun(n-1) + fun(n-2);
    }
public:
    int climbStairs(int n) {
        memset(dp,-1,sizeof dp);
        return fun(n);
    }
};
