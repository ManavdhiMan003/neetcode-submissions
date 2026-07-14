class Solution {
    void fun(vector<int> v[],vector<bool> &vist,int x){
        vist[x] = true;
        for(auto i:v[x]){
            if(vist[i]==false) fun(v,vist,i);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> v[n];
        for(auto x:edges){
            v[x[0]].push_back(x[1]);
            v[x[1]].push_back(x[0]);
        }
        vector<bool> vist(n,false);
        int ans=0;

        for(int i=0;i<n;i++){
            if(vist[i]==false){
                fun(v,vist,i);
                ans++;
            }
        }
        return ans;
    }
};
