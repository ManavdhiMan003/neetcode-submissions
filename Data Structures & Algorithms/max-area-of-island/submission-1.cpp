class Solution {
    int n,m;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,-1,1};
    int dfs(vector<vector<int>> &v,vector<vector<int>> &vist,int x, int y){
        int ans =  0;
        vist[x][y]=1;
        for(int z = 0;z<4;z++){
            int cx = x+dx[z];
            int cy = y+dy[z];
            if(cx>=0 and cx<n and cy>=0 and cy<m and v[cx][cy]==1 and vist[cx][cy]==0){
                vist[cx][cy]=1;
                ans += dfs(v,vist,cx,cy)+1;
            }
        }
        return ans;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& v) {
        n = v.size();
        m = v[0].size();
        vector<vector<int>> vist(n,vector<int> (m,0));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vist[i][j]==0 and v[i][j]==1){
                    ans = max(ans,1+dfs(v,vist,i,j));
                }
            }
        }
        return ans;
    }
};
