class Twitter {
private:
    #define FEED_SIZE 10
    
    typedef pair<int, int> PI;

    // userId -> { {time, tweetId} }
    unordered_map<int, set<PI>> userTweetsMap;
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
        set<PI>& tweets = userTweetsMap[userId];
        // time of the curr tweet
        time++;
        // push the curr tweet in tweets
        tweets.insert({time, tweetId});
        // only a max of 'FEED_SIZE' tweets are required to be stored
        // so remove the oldest tweet
        if(tweets.size() == FEED_SIZE + 1)
            tweets.erase(tweets.begin());
    }
    
    vector<int> getNewsFeed(int userId) {
        // min-heap { time, tweetId } holds a max 'FEED_SIZE' most recent tweets
        priority_queue<PI, vector<PI>, greater<PI>> pq; 

        // assume the user is a follower of itself to simplify the code
        userFollowersMap[userId].insert(userId);

        // insert all the follower tweets in heap
        for(auto followerId: userFollowersMap[userId])
            for(auto [time, tweetId]: userTweetsMap[followerId])
            {
                pq.push({time, tweetId});
                // only a max of 'FEED_SIZE' tweets are required to be stored
                if(pq.size() == FEED_SIZE + 1)
                    pq.pop();
            }

        // undo the itself follower step
        userFollowersMap[userId].erase(userId);

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