class Solution {
    int n,m;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,-1,1};
    int dfs(vector<vector<int>> &v,int x, int y){
        int ans =  0;
        v[x][y]=0;
        for(int z = 0;z<4;z++){
            int cx = x+dx[z];
            int cy = y+dy[z];
            if(cx>=0 and cx<n and cy>=0 and cy<m and v[cx][cy]==1 ){
                v[cx][cy]=0;
                ans += dfs(v,cx,cy)+1;
            }
        }
        return ans;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& v) {
        n = v.size();
        m = v[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]==1){
                    ans = max(ans,1+dfs(v,i,j));
                }
            }
        }
        return ans;
    }
};
