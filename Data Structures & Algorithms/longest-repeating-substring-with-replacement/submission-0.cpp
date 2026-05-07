class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int ans=0;
        int l=0,freq=0;
        for(int r=0;r<s.size();r++){
            mp[s[r]]++;
            freq = max(freq,mp[s[r]]);
            while((r-l+1)-freq>k){
                mp[s[l]]--;
                l++;
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};

