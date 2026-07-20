class Solution {
    int fun(string s,int l,int r){
        int n = s.length();
        int cnt = 0;
        while(l>=0 and r<n and s[l]==s[r]){
            cnt++;
            l--;
            r++;
        }
        return cnt;
    }
public:
    int countSubstrings(string s) {
        int ans = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            ans += fun(s,i,i);
            ans += fun(s,i,i+1);
        }
        return ans;
    }
};
