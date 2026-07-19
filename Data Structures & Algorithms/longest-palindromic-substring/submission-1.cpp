class Solution {
    string odd(string s,int x){
        int l=x-1;
        int r = x+1;
        int n = s.length();
        string ans = "";
        ans+=s[x];
        while(l>=0 and r<n){
            if(s[l]==s[r]){
                ans = s[l]+ans;
                ans = ans+s[r];
            }else break;
            l--;
            r++;
        }
        return ans;
    }
    string even(string s,int x){
        string a = incN(s,x,x+1);
        string b = incP(s,x,x-1);
        // cout<<a<<" -> "<<b<<endl;
        return (a.size()>b.size())?a:b;
    }
    string incN(string s,int x,int i){
        int n = s.length();
        string ans = "";
        ans+=s[x];
        if(i>=n) return ans;
        if(s[x]!=s[i]) return ans;

        ans+=s[i];
        int l = x-1;
        int r = i+1;
        while(l>=0 and r<n){
            if(s[l]==s[r]){
                ans = s[l]+ans;
                ans = ans+s[r];
            }else break;
            l--;
            r++;
        }
        // cout<<ans<<endl;
        return ans;
    }
    string incP(string s,int x,int i){
        int n = s.length();
        string ans = "";
        ans+=s[x];
        if(i<0) return ans;
        if(s[x]!=s[i]) return ans;

        ans=s[i]+ans;

        int l = i-1;
        int r = x+1;
        while(l>=0 and r<n){
            if(s[l]==s[r]){
                ans = s[l]+ans;
                ans = ans+s[r];
            }else break;
            l--;
            r++;
        }
        // cout<<ans<<endl;

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
