class Solution {
    void fun(int x,vector<int> &v,vector<int> &temp,vector<vector<int>> &ans,int target){
        if(target<0) return;
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(x>=v.size()) return;
        temp.push_back(v[x]);
        fun(x,v,temp,ans,target-v[x]);
        temp.pop_back();
        fun(x+1,v,temp,ans,target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        fun(0,nums,temp,ans,target);
        return vector<vector<int>> (ans.begin(),ans.end());
    }
};
