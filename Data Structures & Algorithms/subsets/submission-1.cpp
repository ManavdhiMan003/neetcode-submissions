class Solution {
    void fun(int x,vector<int> &v,vector<vector<int>> &ans,vector<int> &temp){
        if(x==v.size()){
            ans.push_back(temp);
            return;
        }
        fun(x+1,v,ans,temp);
        temp.push_back(v[x]);
        fun(x+1,v,ans,temp);
        temp.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        fun(0,nums,ans,temp);
        return ans;
    }
};
