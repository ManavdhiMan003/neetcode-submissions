class Solution {
public:
    int maxArea(vector<int>& v) {
        int n = v.size();
        int s = 0, e=n-1;
        int ans=0;
        while(s<e){
            int area = min(v[s],v[e])*(e-s); 
            ans = max(ans,area);
            if(v[s]>v[e]) e--;
            else s++;
        }
        return ans;
    }
};
