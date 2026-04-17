class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> ans;
        for(auto x:strs){
            vector<int> cnt(26,0);
            for(auto y:x){
                cnt[y-'a']++;
            }
            string key=to_string(cnt[0]);
            for(int i=1;i<26;i++) key+='|' + to_string(cnt[i]);
            mp[key].push_back(x);
        }
        for(auto x:mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};
