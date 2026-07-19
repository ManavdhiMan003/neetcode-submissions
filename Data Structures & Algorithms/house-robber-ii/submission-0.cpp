#include<bits/stdc++.h>
class Solution {
    int dp[105][2];
    int fun(vector<int> &v,int x,int inc){
        if(x>=v.size() || (inc and x==v.size()-1)) return 0;
        if(dp[x][inc]!=-1) return dp[x][inc];
        return dp[x][inc] = max(fun(v,x+2,inc || x==0)+v[x],fun(v,x+1,inc));
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        memset(dp,-1,sizeof dp);
        return max(fun(nums,0,true),fun(nums,1,false));
    }
};
