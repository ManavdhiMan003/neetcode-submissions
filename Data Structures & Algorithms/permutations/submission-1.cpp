class Solution {
    int n;
    int total;
    bool check(vector<bool> &vist){
        for(auto x:vist) if(x==false) return false;
        return true;
    }
    void fun(vector<int> &v,vector<int> temp,vector<vector<int>> &ans,vector<bool> vist){
        if(ans.size()==total){
            return;
        }
        if(check(vist)){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<v.size();i++){
            if(vist[i]==false){
                vist[i]=true;
                temp.push_back(v[i]);
                fun(v,temp,ans,vist);
                temp.pop_back();
                vist[i]=false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        if(n==1) return {nums};
        int x = n;
        total = 1;
        while(x!=1){
            total *= x;
            x--;
        }
        vector<int> temp;
        vector<bool> vist(n,false);
        vector<vector<int>> ans;
        fun(nums,temp,ans,vist);
        return ans;
    }
};
