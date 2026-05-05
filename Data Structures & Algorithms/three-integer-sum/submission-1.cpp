class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        sort(v.begin(),v.end());
        int n=v.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(v[i]>0) break;
            if(i>0 and v[i]==v[i-1]) continue;
            int s=i+1,e=n-1;
            while(s<e){
                int sum = v[s]+v[e]+v[i];
            
                if(sum>0) e--;
                else if(sum<0){
                    s++;
                }else{
                    ans.push_back({v[i],v[s],v[e]});
                    s++;
                    e--;
                    while(s<e and v[s]==v[s-1]){
                        s++;
                    }
                }
            }
            
        }
        return ans;
    }
};
