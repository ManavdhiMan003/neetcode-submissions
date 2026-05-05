class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0;
        int ans=0;
        unordered_map<char,int> st;
        while(r<s.length()){
            if(st.find(s[r])!=st.end()){
                l = max(st[s[r]]+1,l);
            }
            st[s[r]]=r;
            r++;
            ans = max(ans,r-l);
        }
        return ans;
    }
};
