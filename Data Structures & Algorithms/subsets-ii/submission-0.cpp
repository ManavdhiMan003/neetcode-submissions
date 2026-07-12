class Solution {
    void fun(vector<int> &v,set<vector<int>> &ans,vector<int> temp,int x){
        if(x==v.size()){
            ans.insert(temp);
            return;
        }

        fun(v,ans,temp,x+1);
        temp.push_back(v[x]);
        fun(v,ans,temp,x+1);
        temp.pop_back();
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        vector<int> temp;
        set<vector<int>> ans;
        fun(nums,ans,temp,0);
        return vector<vector<int>> (ans.begin(),ans.end());
    }
};
