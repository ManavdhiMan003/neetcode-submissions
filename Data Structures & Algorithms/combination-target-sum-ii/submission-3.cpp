class Solution {
    void fun(int x,vector<int> &v,int t,set<vector<int>> &ans,vector<int> temp){
        if(t==0){
            ans.insert(temp);
            return;
        }
        if(x>=v.size() or t<0) return;
        
        
        temp.push_back(v[x]);
        fun(x+1,v,t-v[x],ans,temp);
        temp.pop_back();

        while(x+1<v.size() and v[x]==v[x+1]) x++;
        fun(x+1,v,t,ans,temp);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& v, int target) {
        sort(v.begin(),v.end());
        vector<int> temp;
        set<vector<int>> ans;
        fun(0,v,target,ans,temp);
        return vector<vector<int>> (ans.begin(),ans.end());
    }
};
