class Twitter {
    unordered_map<int,unordered_set<int>> followMap;
    unordered_map<int,vector<pair<int,int>>> tweets;
    int time;
public:
    Twitter() {
        followMap.clear();
        time=0;
        tweets.clear();
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {

        vector<pair<int,int>> feed = tweets[userId];
        
        for(int x:followMap[userId]){
            feed.insert(feed.end(),tweets[x].begin(),tweets[x].end());
        }

        sort(feed.begin(),feed.end(),[](auto &a,auto &b){
            return a.first>b.first;
        });
        vector<int> ans;
        for(auto x:feed){
            if(ans.size()==10) break;
            ans.push_back(x.second);
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId) followMap[followerId].insert(followeeId);

    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};


// userid -> followers id / unfollow?

// userID -> follow /. unfollow

// id - tweetId




