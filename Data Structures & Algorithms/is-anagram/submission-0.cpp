class Solution {
public:
    bool isAnagram(string s, string t) {
        int mp[26]={0};
        if(s.length()!=t.length()) return false;
        for(auto x:s) mp[x-'a']++;
        for(auto x:t) mp[x-'a']--;
        for(auto x:mp) if(x!=0) return false;
        return true;
    }
};
