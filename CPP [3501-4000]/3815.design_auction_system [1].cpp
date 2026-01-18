class AuctionSystem {
private:
    // itemId -> {(amount, userId)}
    unordered_map<int, set<pair<int, int>>> mp1;
    // itemId -> {userId -> amount}
    unordered_map<int, unordered_map<int, int>> mp2;
    
public:
    AuctionSystem() {
        this->mp1.clear();
        this->mp2.clear();
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        int oldAmount = mp2[itemId][userId];
        
        if(mp1[itemId].find({oldAmount, userId}) != mp1[itemId].end())
            updateBid(userId, itemId, bidAmount);
        else{
            mp1[itemId].insert({bidAmount, userId});
            mp2[itemId][userId] = bidAmount;
        }
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        int oldAmount = mp2[itemId][userId];

        mp1[itemId].erase({oldAmount, userId});
        mp1[itemId].insert({newAmount, userId});
        mp2[itemId][userId] = newAmount;
    }
    
    void removeBid(int userId, int itemId) {
        int oldAmount = mp2[itemId][userId];

        mp1[itemId].erase({oldAmount, userId});
        mp2[itemId].erase(userId);
        if(mp2[itemId].empty())
            mp2.erase(itemId);
    }
    
    int getHighestBidder(int itemId) {
        return mp1[itemId].empty() ? -1 : mp1[itemId].rbegin()->second;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */