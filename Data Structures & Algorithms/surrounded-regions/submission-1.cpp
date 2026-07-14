class Solution {
    int n,m;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    void fun(vector<vector<char>> &v,int x,int y){
        v[x][y] = '.';
        for(int z = 0;z<4;z++){
            int cx = x+dx[z];
            int cy = y+dy[z];
            if(cx>=0 and cx<n and cy>=0 and cy<m and v[cx][cy]=='O'){
                v[cx][cy] = '.';
                fun(v,cx,cy);
            }
        }
    }
public:
    void solve(vector<vector<char>>& v) {
        n = v.size();
        m = v[0].size();

        for(int i=0;i<n;i++){
            if(v[i][0]=='O'){
                fun(v,i,0);
            }
            if(v[i][m-1]=='O') fun(v,i,m-1);
        }

        for(int i=0;i<m;i++){
            if(v[0][i]=='O') fun(v,0,i);
            if(v[n-1][i]=='O') fun(v,n-1,i);
        }

        for(auto x:v){
            for(auto y:x) cout<<y<<" ";
            cout<<endl;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]=='.') v[i][j]='O';
                else if(v[i][j]=='O') v[i][j]='X';
            }
        }
    }
};
