class Solution {
    bool check(int x,int y,vector<string> &v){
        int n = v.size();
        for(int i=0;i<n;i++){
            if(i==x) continue;
            if(v[i][y]=='Q') return false;
        }
        for(int j=0;j<n;j++){
            if(j==y) continue;
            if(v[x][j]=='Q') return false;
        }

        for(int i=x-1,j=y-1;i>=0 and j>=0 ; i--,j--){
            if(v[i][j]=='Q') return false;
        }

        for(int i=x+1,j=y+1;i<n and j<n; i++,j++){
            if(v[i][j]=='Q') return false;
        }

        for(int i=x-1,j=y+1; i>=0 and j<n;i--,j++){
            if(v[i][j]=='Q') return false;
        }
        for(int i=x+1,j=y-1;i<n and j>=0;i++,j--){
            if(v[i][j]=='Q') return false;
        }
        return true;
    }
    void fun(int x,vector<string> &v,set<vector<string>> &ans){
        if(x == v.size()){
            ans.insert(v);
            return;
        }
        for(int y=0;y<v.size();y++){
            if(check(x,y,v)){
                v[x][y]='Q';
                fun(x+1,v,ans);
                v[x][y]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        set<vector<string>> ans;

        vector<string> v(n,string(n,'.'));
        fun(0,v,ans);
        return vector<vector<string>> (ans.begin(),ans.end());
    }
};
