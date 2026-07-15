class Solution {
    bool dif(string &a,string &b){
        int cnt=0;
        for(int i=0;i<a.length();i++){
            if(a[i]!=b[i]){
                cnt++;
                if(cnt>1) return false;
            }
        }
        return true;
    }
public:
    int ladderLength(string st, string end, vector<string>& v) {
        queue<pair<string,int>> q;
        q.push({st,1});
        set<string> vist;
        while(!q.empty()){
            string nxt = q.front().first;
            int len = q.front().second;
            q.pop();
            if(nxt==end) return len;
            for(auto x:v){
                if(vist.find(x)==vist.end()){
                    if(dif(x,nxt)){
                        q.push({x,len+1});
                        vist.insert(x);
                    }
                }
            }
        }
        return 0;
    }
};
