/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int,int> mp;
        for(auto x:intervals){
            mp[x.start]+=1;
            mp[x.end]-=1;
        }

        int ans = 0;
        int count = 0;
        for(auto x:mp){
            count += x.second;
            ans = max(ans,count);
        }
        return ans;
    }
};
