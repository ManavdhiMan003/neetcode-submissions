class Solution {
public:
    bool check(vector<int> &cmp,vector<int> &mp){
        for(int i=0;i<26;i++){
            if(cmp[i]!=mp[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s2.length()<s1.length()) return false;
        vector<int> mp(26,0);
        for(auto x:s1) mp[x-'a']++;
        vector<int> cmp(26,0);
        int l=0;    
        for(int r=0;r<s2.length();r++){
            cmp[s2[r]-'a']++;
            if(r-l+1>s1.length()){
                cmp[s2[l]-'a']--;
                l++;
            }
            // cout<<r<<" "<<l<<endl;
            // cout<<s2[r]<<" "<<s2[l]<<endl;
            // for(int i=0;i<26;i++){
            //     cout<<mp[i]<<" ";
            // }
            // cout<<endl;
            // for(int i=0;i<26;i++){
            //     cout<<cmp[i]<<" ";
            // }
            // cout<<endl;
            if(check(cmp,mp)) return true;
        }
        return false;
    }
};
