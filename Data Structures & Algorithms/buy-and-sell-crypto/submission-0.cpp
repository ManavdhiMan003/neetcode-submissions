class Solution {
public:
    int maxProfit(vector<int>& v) {
        int ans=0;
        int b=v[0];
        for(int i=1;i<v.size();i++){
            b = min(v[i],b);
            ans = max(ans,v[i]-b);
        }
        return ans;
    }
};
