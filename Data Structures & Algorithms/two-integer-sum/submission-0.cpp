class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int x = nums[i];
            int v = target - x;
            if(mp.find(v)!=mp.end()){
                return {mp[v],i};
            }
            mp[x]=i;
        }
        return {};
    }
};
