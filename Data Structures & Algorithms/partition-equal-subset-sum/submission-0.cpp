class Solution {
    map<pair<int,pair<int,int>>,bool> dp;
    bool fun(vector<int> &v,int i,int a,int b){
        if(i>v.size()) return false;
        if(i==v.size()){
            if(a==b) return true;
            return false;
        }
        if(dp.find({i,{a,b}})!=dp.end()) return dp[{i,{a,b}}];
        return dp[{i,{a,b}}] = fun(v,i+1,a+v[i],b) || fun(v,i+1,a,b+v[i]);
    }
public:
    bool canPartition(vector<int>& v) {
        int n = v.size();
        int sum = 0;
        for(auto x:v) sum+=x;
        if(sum%2) return false;
        dp.clear();
        return fun(v,0,0,0);

    }
};
