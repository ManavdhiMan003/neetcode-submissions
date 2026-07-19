class Solution {
    string odd(string s,int x){
        int l=x;
        int r = x;
        int n = s.length();
        int len = 0;
        string ans = "";
        while(l>=0 and r<n){
            if(s[l]==s[r]){
                if((r-l+1)>len){
                    len = r-l+1;
                    ans = s.substr(l,r-l+1);
                }
            }else break;
            l--;
            r++;
        }
        return ans;
    }
    string even(string s,int x){
        int l=x;
        int r = x+1;
        int n = s.length();
        int len = 0;
        string ans = "";
        while(l>=0 and r<n){
            if(s[l]==s[r]){
                if((r-l+1)>len){
                    len = r-l+1;
                    ans = s.substr(l,r-l+1);
                }
            }else break;
            l--;
            r++;
        }
        return ans;
    }
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string ans = "";
        for(int i=0;i<n;i++){
            string a = odd(s,i);
            string b = even(s,i);
            // cout<<a<<" "<<b<<endl;
            if(a.size()>=b.size() and ans.size()<a.size()){
                ans=a;
            }else if(b.size()>a.size() and ans.size()<b.size()){
                ans=b;
            }
        }
        return ans;
        
    }
};
