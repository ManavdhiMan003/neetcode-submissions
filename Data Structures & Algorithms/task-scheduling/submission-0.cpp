class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        vector<int> v(26,0);

        for(auto x:tasks){
            v[x-'A']++;
        }

        for(auto x:v) if(x>0)pq.push(x);
        queue<pair<int,int>> q;
        int time = 0;
        while(!pq.empty() || !q.empty()){
            time++;

            if(pq.empty()){
                time = q.front().second;
            }else{
                int t = pq.top()-1;
                pq.pop();
                if(t>0) q.push({t,time+n});
            }
            if(!q.empty() and q.front().second==time){
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};

