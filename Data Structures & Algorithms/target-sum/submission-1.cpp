class Solution {
    map<pair<int,int>,int> dp;
    int fun(vector<int> &v,int tar,int sum,int i){
        if(i>=v.size()){
            if(tar==sum) return 1;
            return 0;
        }
        if(dp.find({i,sum})!=dp.end()) return dp[{i,sum}];
        return dp[{i,sum}] = fun(v,tar,sum+v[i],i+1) + fun(v,tar,sum-v[i],i+1);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        dp.clear();
        return fun(nums,target,0,0);
    }
};
