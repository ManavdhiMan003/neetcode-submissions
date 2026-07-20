class Solution {
    unordered_map<int,bool>dp;
    bool fun(string s,vector<string> &dict,int i){
        if(i==s.length()) return true;
        if(dp.find(i)!=dp.end()) return dp[i];
        for(const string &w:dict){
            if(i+w.length()<=s.length() and s.substr(i,w.length())==w){
                if(fun(s,dict,i+w.length())){
                    dp[i] = true;
                    return true;
                }
            }
        }
        return dp[i] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.clear();
        return fun(s,wordDict,0);
    }
};
