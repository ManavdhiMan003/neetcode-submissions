class Solution {
   
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> cnt;
        vector<vector<int>> freq(n+1);
        for(int i:nums){
            cnt[i]++;
        }

        for(auto x:cnt){
            freq[x.second].push_back(x.first);
        }
        vector<int> ans;
        for(int i=n;i>0;i--){
            for(int x:freq[i]){
                ans.push_back(x);
                if(ans.size()==k) return ans;
            }
        }
        return ans;
    }
};
