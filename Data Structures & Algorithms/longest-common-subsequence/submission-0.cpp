class Solution {
    vector<vector<int>> dp;
    int fun(string a,string b,int x,int y){
        if(a.length()<=x or y>=b.length()) return 0;
        if(dp[x][y]!=-1) return dp[x][y];
        if(a[x]==b[y]) return dp[x][y] = 1+fun(a,b,x+1,y+1);
        return dp[x][y] = max(fun(a,b,x+1,y),fun(a,b,x,y+1));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m = text2.length();
        dp.assign(n+1,vector<int> (m,-1));
        return fun(text1,text2,0,0);
    }
};
