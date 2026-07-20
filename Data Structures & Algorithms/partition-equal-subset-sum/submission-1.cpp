class Solution {
    vector<vector<int>> dp;
    bool fun(vector<int> &v,int i,int tar){
        if(i>v.size()) return false;
        if(i==v.size()){
            return tar==0;
        }
        if(tar<0) return false;
        if(dp[i][tar]!=-1) return dp[i][tar];
        // if(dp.find({i,{a,b}})!=dp.end()) return dp[{i,{a,b}}];
        return dp[i][tar] = fun(v,i+1,tar) || fun(v,i+1,tar-v[i]);
    }
public:
    bool canPartition(vector<int>& v) {
        int n = v.size();
        int sum = 0;
        for(auto x:v) sum+=x;
        if(sum%2) return false;
        dp.resize(n,vector<int> (sum/2+1,-1));
        return fun(v,0,sum/2);

    }
};
