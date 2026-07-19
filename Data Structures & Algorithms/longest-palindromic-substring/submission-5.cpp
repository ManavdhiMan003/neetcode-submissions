#include<bits/stdc++.h>
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        bool dp[n+5][n+5];
        memset(dp,false,sizeof dp);
        int id = 0;
        int len = 0;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if((s[i]==s[j]) and ((j-i<=2) || dp[i+1][j-1])){
                    dp[i][j]=true;
                    if(len<(j-i+1)){
                        len = j-i+1;
                        id=i;
                    }
                }
            }
        }
        cout<<len<<" "<<id<<endl;
        return s.substr(id,len);
    }
};
