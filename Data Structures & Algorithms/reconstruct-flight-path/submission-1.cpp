class Solution {
    int n;
    void fun(string s,unordered_map<string,vector<string>> &v,vector<string> &ans){
        while(v[s].size()!=0){
            string nxt = v[s].back();
            v[s].pop_back();
            fun(nxt,v,ans);
        }
        ans.push_back(s);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // sort(tickets.begin(),tickets.end());
        n = tickets.size();
        unordered_map<string,vector<string>> v;
        for(auto x:tickets){
            v[x[0]].push_back(x[1]);
        }
        for(auto &x:v){
            sort(x.second.rbegin(),x.second.rend());
        }

        vector<string> ans;

        fun("JFK",v,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
