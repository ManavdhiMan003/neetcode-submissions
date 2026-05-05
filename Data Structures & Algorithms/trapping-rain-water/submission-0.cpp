class Solution {
public:
    int trap(vector<int>& v) {
        int n=v.size();
        vector<int> pre(n,0), suf(n,0);
        pre[0]=v[0];
        for(int i=1;i<n;i++){
            pre[i] = max(pre[i-1],v[i]);
        }
        suf[n-1]=v[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i] = max(suf[i+1],v[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans += (min(suf[i],pre[i])-v[i]);
        }
        return ans;
    }
};
