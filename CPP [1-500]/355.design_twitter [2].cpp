class Twitter {
private:
    typedef pair<int, int> PI;
    
    // userId -> { {time, tweetId} }
    unordered_map<int, vector<pair<int, int>>> userTweetsMap;
    // userId -> { followerId }
    unordered_map<int, unordered_set<int>> userFollowersMap;

    int time = 0;
    int feedSize = 10;

public:
    Twitter() {
        this->userTweetsMap.clear();
        this->userFollowersMap.clear();
        this->time = 0;
        this->feedSize = 10;
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
        // only a max of 'feedSize' tweets are required to be stored
        if(tweets.size() == feedSize + 1)
            tweets.pop_back();
    }
    
    vector<int> getNewsFeed(int userId) {
        // min-heap { time, tweetId } holds a max 'feedSize' most recent tweets
        priority_queue<PI, vector<PI>, greater<PI>> pq; 

        // assume the user is a follower of itself to simplify the code
        userFollowersMap[userId].insert(userId);

        // insert all the follower tweets in heap
        for(auto followerId: userFollowersMap[userId])
            for(auto [time, tweetId]: userTweetsMap[followerId])
            {
                pq.push({time, tweetId});
                // only a max of 'feedSize' tweets are required to be stored
                if(pq.size() == feedSize + 1)
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