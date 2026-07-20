class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        int n = v.size();
        vector<int> dp(n+1,1);
        for(int i=0;i<n;i++){
            for(int j=i;j>=0;j--){
                if(v[i]>v[j]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
