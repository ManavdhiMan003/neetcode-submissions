class Solution {
    int n,m;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    void fun(vector<vector<int>> &v,vector<vector<bool>> &vist,int x,int y){
        vist[x][y] = true;
        for(int z = 0; z < 4; z++){
            int cx = x + dx[z];
            int cy = y + dy[z];
            if(cx>=0 and cx<n and cy>=0 and cy<m and vist[cx][cy]==false and v[x][y]<=v[cx][cy]){
                vist[cx][cy] = true;
                fun(v,vist,cx,cy);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& v) {
        n = v.size();
        m = v[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> pac(n,vector<bool> (m,false));
        vector<vector<bool>> alt(n,vector<bool> (m,false));
        for(int i=0;i<n;i++){
            fun(v,pac,i,0);
            fun(v,alt,i,m-1);
        }
        for(int i=0;i<m;i++){
            fun(v,pac,0,i);
            fun(v,alt,n-1,i);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j] and alt[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
