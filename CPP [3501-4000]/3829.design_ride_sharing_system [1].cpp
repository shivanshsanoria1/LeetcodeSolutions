class RideSharingSystem {
private:
    queue<int> riders;
    queue<int> drivers;
    vector<bool> isRiderWaiting;

public:
    RideSharingSystem() {
        this->isRiderWaiting.resize(1001, false);
    }
    
    void addRider(int riderId) {
        riders.push(riderId);
        isRiderWaiting[riderId] = true;
    }
    
    void addDriver(int driverId) {
        drivers.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        // remove the riders from queue who have cancelled
        while(!riders.empty() && !isRiderWaiting[riders.front()])
            riders.pop();

        if(riders.empty() || drivers.empty())
            return {-1, -1};

        int driverId = drivers.front();
        drivers.pop();

        int riderId = riders.front();
        riders.pop();
        isRiderWaiting[riderId] = false;

        return {driverId, riderId};
    }
    
    void cancelRider(int riderId) {
        isRiderWaiting[riderId] = false;
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */