class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> v[n];
        vector<int> out(n,0);
        for(auto x:pre){
            v[x[1]].push_back(x[0]);
            out[x[0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++) if(out[i]==0) q.push(i);
        
        while(!q.empty()){
            int nxt = q.front();
            q.pop();
            for(auto x:v[nxt]){
                out[x]--;
                if(out[x]==0) q.push(x);
            }
        }
        for(auto x:out) if(x!=0) return false;
        return true;
        
    }
};
