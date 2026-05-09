class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& v, int k) {
        deque<int> q;
        int n = v.size();
        vector<int> ans(n-k+1);
        int r=0,l=0;
        while(r<n){
            while(!q.empty() and v[q.back()]<v[r]) q.pop_back();

            q.push_back(r);
            if(l>q.front()) q.pop_front();
            if(r+1>=k){
                ans[l] = v[q.front()];
                l++;
            }
            r++;

        }
        return ans;
    }
};
