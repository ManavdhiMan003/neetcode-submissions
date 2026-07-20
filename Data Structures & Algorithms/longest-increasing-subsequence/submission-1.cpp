class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        int n = v.size();
        vector<int> dp;
        int len = 1;
        dp.push_back(v[0]);
        for(int i=1;i<n;i++){
            if(dp.back()<v[i]){
                dp.push_back(v[i]);
                len++;
                continue;
            }
            int id = lower_bound(dp.begin(),dp.end(),v[i]) - dp.begin();
            dp[id] = v[i];
        }
        return len;
    }
};
