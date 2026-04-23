class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        
        stack<int> st;
        int n=v.size();
        vector<int> left(n),right(n);

        for(int i=0;i<n;i++){
            while(!st.empty() and v[st.top()]>=v[i]) st.pop();
            if(!st.empty())left[i] = st.top();
            else left[i] = -1;
            st.push(i);
        }
        
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and v[st.top()]>=v[i]) st.pop();

            if(!st.empty()) right[i]=st.top();
            else right[i] = n;
            st.push(i);
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            left[i]++;
            right[i]--;
            ans = max(ans, v[i]*(right[i] - left[i] + 1 ));
        }
        return ans;

    }
};
