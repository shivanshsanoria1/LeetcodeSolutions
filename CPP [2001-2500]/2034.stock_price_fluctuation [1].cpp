class StockPrice {
private:
    // timestamp -> price
    map<int, int> mp1;
    // price -> freq 
    map<int, int> mp2;

public:
    StockPrice() {
        this->mp1.clear();
        this->mp2.clear();
    }
    
    void update(int timestamp, int price) {
        // timestamp already exists in mp1
        if(mp1.find(timestamp) != mp1.end())
        {
            int oldPrice = mp1[timestamp];

            // decrement the freq of old-price by 1 and 
            // remove it from mp2 if its freq reaches 0
            if(--mp2[oldPrice] == 0)
                mp2.erase(oldPrice);
        }

        mp1[timestamp] = price;
        mp2[price]++;
    }
    
    int current() {
        return mp1.rbegin()->second;
    }
    
    int maximum() {
        return mp2.rbegin()->first;
    }
    
    int minimum() {
        return mp2.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */