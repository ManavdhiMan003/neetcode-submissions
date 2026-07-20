#include<bits/stdc++.h>
class Solution {
    int dp[105];
    int fun(string s,int x){
        if(x==s.length()) return 1;
        if(s[x]=='0') return 0;
        if(dp[x]!=-1) return dp[x];
        int ans = fun(s,x+1);
        if(x<s.length()-1){
            if(s[x]=='1' or (s[x]=='2' and s[x+1]<'7')){
                ans += fun(s,x+2);
            }
        }
        return dp[x]=ans;
    }
public:
    int numDecodings(string s) {
        memset(dp,-1,sizeof dp);
        // return 0;
        return fun(s,0);
    }
};
