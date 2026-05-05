class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0;
        int ans=0;
        set<char> st;
        while(r<s.length()){
            if(st.find(s[r])==st.end()){
                st.insert(s[r]);
                r++;
            }else{
                while(l<=r and st.empty()==false){
                    if(st.find(s[r])==st.end()) break;
                    st.erase(s[l]);
                    l++;
                }
                st.insert(s[r]);
                r++;
            }
            ans = max(ans,r-l);
        }
        return ans;
    }
};
