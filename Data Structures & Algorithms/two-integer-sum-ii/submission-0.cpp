class Solution {
public:
    vector<int> twoSum(vector<int>& v, int t) {
        int s = 0, e = v.size()-1;
        int sum=0;
        while(s<e){
            sum = v[s]+v[e];
            if(sum==t) return {s+1,e+1};
            if(sum>t) e--;
            else s++;
        }
        return {};
    }
};
