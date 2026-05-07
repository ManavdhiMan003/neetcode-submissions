class Solution {
public:
    bool check(vector<int>& cmp,vector<int>& mp){
        for(int i=0;i<256;i++){
            if(cmp[i]<mp[i]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n=s.length(),m=t.length();
        if(m>n) return "";
        vector<int> mp(256,0);
        vector<int> cmp(256,0);
        for(auto x:t) mp[x]++;
        int l=0;
        int ansL=-1,ansR=-1;
        int dif=INT_MAX;
        for(int r=0;r<n;r++){
            cmp[s[r]]++;
            while(check(cmp,mp)){
                if(r-l<dif){
                    ansL=l;
                    ansR=r;
                    dif=r-l;
                }
                
                // cout<<ansL<<" "<<s[ansL]<<" "<<ansR<<" "<<s[ansR]<<endl;
                cmp[s[l]]--;
                l++;
            }
        }
        if(ansL==-1 and ansR==-1) return "";
        return s.substr(ansL,ansR-ansL+1);
    }
};
