class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        unordered_set<string> op;
        op.insert("+");
        op.insert("-");
        op.insert("/");
        op.insert("*");

        for(auto x:tokens){
            if(op.find(x)==op.end()) st.push(x);
            else{
                int a = stoi(st.top());
                st.pop();
                int b = stoi(st.top());
                st.pop();
                if(x=="+"){
                    st.push(to_string(a+b));
                }else if(x=="-"){
                    st.push(to_string(b-a));
                }else if(x=="*"){
                    st.push(to_string(b*a));
                }else if(x=="/"){
                    st.push(to_string(b/a));
                }
            }
        }
        return stoi(st.top());
    }
};
