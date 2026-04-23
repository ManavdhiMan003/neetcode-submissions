class TimeMap {
    unordered_map<string,vector<pair<string,int>>> mp;
public:
    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int t) {
        if(mp.find(key)==mp.end()) return "";
        vector<pair<string,int>> &v = mp[key];
        int s = 0,e = v.size()-1;
        if(v[0].second>t) return "";
        if(v[e].second<t) return v[e].first;
        int id = INT_MIN;
        // cout<<key<<endl;
        while(s<=e){
            int m = s + (e-s)/2;
            // cout<<m<<" "<<v[m].second<<" "<<v[m].first<<endl;
            if(v[m].second==t) return v[m].first;
            if(v[m].second<t){
                s = m+1;
                id = max(id,m);
            }else{
                e = m-1;
            }
        }
        // cout<<id<<endl;
        if(id==INT_MAX) return "";
        return v[id].first;
    }
};
