class Solution {
    void fun(int x,vector<int> &v,set<vector<int>> &ans,vector<int> &temp){
        if(x==v.size()){
            ans.insert(temp);
            return;
        }
        fun(x+1,v,ans,temp);
        temp.push_back(v[x]);
        fun(x+1,v,ans,temp);
        temp.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> temp;
        fun(0,nums,ans,temp);
        return vector<vector<int>> (ans.begin(),ans.end());
    }
};
