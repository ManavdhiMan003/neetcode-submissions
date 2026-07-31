class Solution {
    int fun(vector<int> &v,int tar,int i){
        if(i>=v.size()){
            if(tar==0) return 1;
            return 0;
        }
        return fun(v,tar+v[i],i+1) + fun(v,tar-v[i],i+1);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return fun(nums,target,0);
    }
};
