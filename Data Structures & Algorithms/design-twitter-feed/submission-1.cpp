class Twitter {
    
public:
    // {userID, {time,tweetId}}
    int time = 0;
    map<int,vector<pair<int,int>>> tweet;

    // friend list
    map<int,vector<int>> f;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {

        tweet[userId].push_back({time,tweetId});
        time++;
        
    }
    
    vector<int> getNewsFeed(int userId) {

        vector<int> ans;
        // {time,tweetid}
        priority_queue<pair<int,int>> pq;

        for(auto it : tweet[userId]){
            pq.push({it});
        }

        for (int followeeId : f[userId]) {

            for (auto tweet : tweet[followeeId]) {
                pq.push(tweet);
            }
        }


        int count = 0;
        while (!pq.empty() && count < 10) {

            int tweetId = pq.top().second;
            pq.pop();

            ans.push_back(tweetId);

            count++;
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        //f[followerId].push_back(followeeId);
        auto &v = f[followerId];

        if (find(v.begin(), v.end(), followeeId) == v.end()) {
            v.push_back(followeeId);
        }
        
        
    }
    
    void unfollow(int followerId, int followeeId) {
       auto &v = f[followerId];
       v.erase(remove(v.begin(),v.end(),followeeId), v.end());
        
    }
};
