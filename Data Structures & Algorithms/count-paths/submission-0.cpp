#include<bits/stdc++.h>
class Solution {
    int dp[105][105];
    int fun(int m,int n){
        if(m<0 || n<0) return 0;
        if(m==0 and n==0) return 1;
        if(dp[m][n]!=-1) return dp[m][n];
        return dp[m][n] = fun(m-1,n)+fun(m,n-1);
    }
public:
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof dp);
        return fun(m-1,n-1);
    }
};
