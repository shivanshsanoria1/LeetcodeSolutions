class TweetCounts {
private:
    // tweetName -> { time -> freq }
    unordered_map<string, unordered_map<int, int>> mp;

public:
    TweetCounts() {
        this->mp.clear();
    }
    
    void recordTweet(string tweetName, int time) {
        mp[tweetName][time]++;
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int block = 0;

        if(freq == "minute")
            block = 60;
        else if(freq == "hour")
            block = 3600;
        else // freq == "day"
            block = 86400;

        vector<int> ans;
        for(int i = startTime; i <= endTime; i += block)
        {
            int count = 0;
            for(auto [t, f]: mp[tweetName])
                if(t >= i && t <= min(endTime, i + block - 1))
                    count += f;

            ans.push_back(count);
        }

        return ans;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */