class Solution {
private: 
    int fun(vector<int> &v,int d, int h){
        int ret = 0;
        for(auto &x:v){
            ret += ceil((x+0.0)/d);
        }
        // cout<<ret<<" ";
        if(ret==h) return 0;
        return ret<h?1:-1;
    }
public:
    int minEatingSpeed(vector<int>& v, int h) {
        int s = 1;
        int e = *max_element(v.begin(),v.end());
        int ans = INT_MAX;
        while(s<=e){
            int m = s + (e-s)/2;
            int ret = fun(v,m,h);
            // cout<<m<<" "<<ret<<endl;
            if(ret >= 0){
                e = m - 1;
                ans = min(ans,m);
            }else s = m + 1;
        }
        return ans;
    }
};
