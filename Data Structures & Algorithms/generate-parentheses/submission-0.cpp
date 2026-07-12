class Solution {
    bool valid(string s){
        stack<char> st;
        for(auto x:s){
            if(x=='(') st.push(x);
            else{
                if(st.size()==0) return false;
                st.pop();
            }
        }
        return st.size()==0;
    }
    void fun(int x,string temp,vector<string> &ans){
        if(x==temp.size()){
            if(valid(temp)) ans.push_back(temp);
            return;
        }
        temp[x] = '(';
        fun(x+1,temp,ans);
        temp[x] = ')';
        fun(x+1,temp,ans);

    }
public:
    vector<string> generateParenthesis(int n) {
        n = n+n;
        string temp(n,'.');
        vector<string> ans;
        fun(0,temp,ans);
        return ans;
    }
};
