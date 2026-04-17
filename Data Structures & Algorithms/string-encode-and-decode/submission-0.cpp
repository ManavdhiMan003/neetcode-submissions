class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";
        vector<int> sizes;
        string res = "";
        for(auto x:strs) sizes.push_back(x.size());

        for(int sz:sizes){
            res += to_string(sz)+',';
        }
        res+="#";
        for(auto x:strs) res+=x;
        return res;
    }

    vector<string> decode(string s) {
        if(s.empty()) return {};

        vector<int> sz;
        vector<string> ans;
        int i=0;
        while(s[i]!='#'){
            string cur="";
            while(s[i]!=','){
                cur+=s[i];
                i++;
            }
            sz.push_back(stoi(cur));
            i++;
        }

        i++;
        for(int x:sz){
            ans.push_back(s.substr(i,x));
            i+=x;
        }
        return ans;
    }
};
