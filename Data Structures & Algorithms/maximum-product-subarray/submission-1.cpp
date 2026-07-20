class Solution {
public:
    int maxProduct(vector<int>& v) {
        int n = v.size();
        int mx = 1;
        int mn = 1;
        int ans = INT_MIN;
        for(auto x:v){
            int temp = mx;    
            mx = max({mx*x,mn*x,x});
            mn = min({temp*x,mn*x,x});
            ans = max({ans,mx,mn});
        }
        return ans;
    }
};
