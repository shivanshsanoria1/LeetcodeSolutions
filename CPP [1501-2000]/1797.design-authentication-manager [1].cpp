class AuthenticationManager {
private:
    // tokenId -> expiration time
    unordered_map<string, int> mp;
    // time duration before a token is expired
    int duration = 0;

public:
    AuthenticationManager(int timeToLive) {
        this->mp.clear();
        this->duration = timeToLive;
    }
    
    // T.C.=O(1)
    void generate(string tokenId, int currentTime) {
        // tokenId not found in map, so create a new tokenId
        if(mp.find(tokenId) == mp.end())
            mp[tokenId] = currentTime + duration;
        // tokenId has expired, so remove it from map
        else if(mp[tokenId] <= currentTime)
            mp.erase(tokenId);
    }
    
    // T.C.=O(1)
    void renew(string tokenId, int currentTime) {
        // unexpired tokenId found in map
        if(mp.find(tokenId) != mp.end() && mp[tokenId] > currentTime)
            mp[tokenId] = currentTime + duration;
    }
    
    // T.C.=O(n)
    int countUnexpiredTokens(int currentTime) {
        int tokenCount = 0;
        unordered_set<string> expiredTokenIds;

        for(auto& [tokenId, expTime]: mp)
        {
            if(expTime <= currentTime)
                expiredTokenIds.insert(tokenId);
            else
                tokenCount++;
        }

        for(auto& expiredTokenId: expiredTokenIds)
            mp.erase(expiredTokenId);

        return tokenCount;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */

// a token is considered expired if its 
// expiration time <= curr time 