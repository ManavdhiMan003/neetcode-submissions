class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        unordered_map<int,int> mp;
        int ans=0;
        for(auto x:v){
            if(!mp[x]){
                mp[x] = mp[x-1]+mp[x+1]+1;
                mp[x-mp[x-1]]=mp[x];
                mp[x+mp[x+1]]=mp[x];
                ans = max(ans,mp[x]);
            }
        }
        return ans;
    }
};
