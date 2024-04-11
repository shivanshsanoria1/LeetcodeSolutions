class SeatManager {
private:
    set<int> unreservedSeats;

public:
    SeatManager(int n) {
        this->unreservedSeats.clear();

        // initially all seats from [1, n]
        // are unreserved
        for(int i=1; i<=n; i++)
            this->unreservedSeats.insert(i);
    }
    
    // T.C.=O(logn)
    int reserve() {
        auto itr = unreservedSeats.begin();
        int seat = *itr;
        unreservedSeats.erase(itr);
        return seat;
    }
    
    // T.C.=O(logn)
    void unreserve(int seatNumber) {
        unreservedSeats.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */