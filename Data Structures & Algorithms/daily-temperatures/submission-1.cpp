class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& v) {
        stack<pair<int,int>> st;
        int n = v.size();
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            while(st.empty()==false and st.top().first<=v[i]){
                st.pop();
            }
            if(st.empty()==true){
                ans[i]=0;
            }else{
                ans[i] = st.top().second-i;
            }
            st.push({v[i],i});
        }
        return ans;
    }
};
