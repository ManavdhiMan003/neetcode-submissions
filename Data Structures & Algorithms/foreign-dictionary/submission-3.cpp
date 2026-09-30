class Solution {
    // set<char> seen;
    // set<char> used;
    // pair<char,char> fun(string a,string b){
    //     int n = a.length();
    //     int m = b.length();
    //     int i = 0,j = 0;
    //     while(i<n and j<m){
    //         if(a[i]!=b[j]){
    //             return {a[i],b[j]};
    //         }
    //         i++;j++;
    //     }
    //     return {'#','#'};
    // }
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,unordered_set<char>> mp;
        unordered_map<char,int> inc;

        int n = words.size();
        for(auto x:words){
            for(auto i:x){
                mp[i] = unordered_set<char>();
                inc[i] = 0;
            }
        }
        for(int i=0;i<n-1;i++){
            string w1 = words[i], w2 = words[i+1];

            int mnL = min(w1.length(),w2.length());

            if(w1.size() > w2.size() and w1.substr(0,mnL)==w2.substr(0,mnL)){
                return "";
            }

            for(int j=0;j<mnL;j++){
                if(w1[j]!=w2[j]){
                    if(!mp[w1[j]].count(w2[j])){
                        mp[w1[j]].insert(w2[j]);
                        inc[w2[j]]++;
                    }
                    break;
                }
            }
        }

        queue<char> q;
        for(auto x:inc){
            if(x.second==0){
                q.push(x.first);
            }
        }
        

        string ans = "";
        while(!q.empty()){
            auto nxt = q.front();
            q.pop();
            ans += nxt;
            for(auto x:mp[nxt]){
                inc[x]--;
                if(inc[x]==0){
                    q.push(x);
                    // inc.erase(x);
                }
            }
        }
        // if(inc.size()!=0) return "";
        // reverse(ans.begin(),ans.end());
        return ans.size()==inc.size()?ans:"";
    }
};
