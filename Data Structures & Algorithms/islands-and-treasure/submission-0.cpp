class Solution {
    int n,m;
    struct data{
        int x,y;
        int dist;
    };
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    void fun(vector<vector<int>> &v,int x,int y){
        queue<data> q;
        q.push({x,y});
        while(!q.empty()){
            data t = q.front();
            q.pop();
            for(int z = 0;z<4;z++){
                int cx = t.x + dx[z];
                int cy = t.y + dy[z];
                if(cx>=0 and cx<n and cy>=0 and cy<m){
                    if(v[cx][cy]==-1 or v[cx][cy]==0){
                        continue;
                    }
                    if(v[cx][cy]>t.dist+1){
                        v[cx][cy] = min(v[cx][cy],t.dist+1);
                        q.push({cx,cy,t.dist+1});
                    }
                   
                }
            }
        }
    }
public:
    void islandsAndTreasure(vector<vector<int>>& v) {
        n = v.size();
        m = v[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]==0) fun(v,i,j);
            }
        }
    }
};
