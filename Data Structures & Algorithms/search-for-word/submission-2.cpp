class Solution {
    int n,m;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    bool fun(vector<vector<char>> &v,string s,int x,int y,int i){
        if(i==s.length()) return true;
        if(x<0 or x>=n or y<0 or y>=m or v[x][y]=='*' or v[x][y]!=s[i]) return false;
        bool ret = false;
        v[x][y]='*';
        for(int z=0;z<4;z++){
            int cx = x + dx[z];
            int cy = y + dy[z];
            ret |= fun(v,s,cx,cy,i+1);
        }
        v[x][y] = s[i];
        return ret;
    }
public:
    bool exist(vector<vector<char>>& v, string s) {
        n = v.size();
        m = v[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[0]==v[i][j]){
                    if(s.length()==1) return true;
                    if(fun(v,s,i,j,0)) return true;
                }
            }
        }
        return false;
    }
};
