class Solution {
public:
    bool isPalindrome(string s) {
        string clean = "";
        for(auto x:s){
            if(x>='A' and x<='Z'){
                int t = x-'A';
                char add = char('a'+t);
                clean+=add;
            }
            else if((x>='a' and x<='z')){
                clean+=x;
            }else if((x>='0' and x<='9')) clean+=x;
        }

        string cmp = clean;
        reverse(clean.begin(),clean.end());
        return clean == cmp;
    }
};
