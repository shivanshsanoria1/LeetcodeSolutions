class Twitter {
private:
    #define FEED_SIZE 10

    typedef pair<int, int> PI;
    
    // userId -> { {time, tweetId} }
    unordered_map<int, vector<PI>> userTweetsMap;
    // userId -> { followerId }
    unordered_map<int, unordered_set<int>> userFollowersMap;

    int time = 0;

public:
    Twitter() {
        this->userTweetsMap.clear();
        this->userFollowersMap.clear();
        this->time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        // tweets of the curr user
        vector<PI>& tweets = userTweetsMap[userId];
        // time of the curr tweet
        time++;
        // push the curr tweet in tweets
        tweets.push_back({time, tweetId});
        // sort the tweets in decreasing order of time
        sort(tweets.begin(), tweets.end(), greater<PI>());
        // only a max of 'FEED_SIZE' tweets are required to be stored
        // so remove the oldest tweet
        if(tweets.size() == FEED_SIZE + 1)
            tweets.pop_back();
    }
    
    vector<int> getNewsFeed(int userId) {
        // build a vector of the tweets of curr user and all its followers
        vector<PI> tweets;
        for(auto [time, tweetId]: userTweetsMap[userId])
            tweets.push_back({time, tweetId});
        for(auto followerId: userFollowersMap[userId])
            for(auto [time, tweetId]: userTweetsMap[followerId])
                tweets.push_back({time, tweetId});

        // min-heap { time, tweetId } holds a max 'FEED_SIZE' most recent tweets
        priority_queue<PI, vector<PI>, greater<PI>> pq; 
        // insert all the follower tweets in heap
        for(auto [time, tweetId]: tweets)
        {
            pq.push({time, tweetId});
            // only a max of 'FEED_SIZE' tweets are required to be stored
            if(pq.size() == FEED_SIZE + 1)
                pq.pop();
        }

        // pop the tweets from heap and add it to 'ans'
        vector<int> ans;
        while(!pq.empty())
        {
            auto [time, tweetId] = pq.top();
            pq.pop();
            ans.push_back(tweetId);
        }
        // reverse the tweetIds to arrange them in decreasing order of time
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        userFollowersMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        userFollowersMap[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */