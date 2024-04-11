class SeatManager {
private:
    // min-heap
    priority_queue<int, vector<int>, greater<int>> unreservedSeats;

public:
    SeatManager(int n) {
        // initially all seats from [1, n]
        // are unreserved
        for(int i=1; i<=n; i++)
            this->unreservedSeats.push(i);
    }
    
    // T.C.=O(logn)
    int reserve() {
        int seat = unreservedSeats.top();
        unreservedSeats.pop();
        return seat;
    }
    
    // T.C.=O(logn)
    void unreserve(int seatNumber) {
        unreservedSeats.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */