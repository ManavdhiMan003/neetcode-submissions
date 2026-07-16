class Solution {
    struct data{
        int x,y,h,t;
    };
    struct cmp{
        bool operator()(const data &a,const data &b){
            if(a.t==b.t) return a.h<b.h;
            return a.t<b.t;
        }
    };
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

public:
    int swimInWater(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();

        priority_queue<data,vector<data>,cmp> pq;


        pq.push({0,0,v[0][0],0});
        vector<vector<int>> dist(n,vector<int> (m,INT_MAX));
        dist[0][0] = v[0][0];
        while(!pq.empty()){
            int x = pq.top().x;
            int y = pq.top().y;
            int t = pq.top().t;
            int h = pq.top().h;
            pq.pop();
            for(int z = 0;z<4;z++){
                int cx = x+dx[z];
                int cy = y+dy[z];
                
                if(cx>=0 and cx<n and cy>=0 and cy<m){
                    int cal = min(dist[cx][cy],max(t+1,max(v[cx][cy],h)));
                    if(dist[cx][cy]>cal){
                        dist[cx][cy] = cal;
                        pq.push({cx,cy,dist[cx][cy],t+1});
                    }
                }
            }

        }
        for(auto x:dist){
            for(auto y:x){
                cout<<y<<" "; 
            }
            cout<<endl;
        }
        return dist[n-1][m-1];
    }
};
