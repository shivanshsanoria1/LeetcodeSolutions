class UndergroundSystem {
private:
    // customer id -> {start station, start time}
    unordered_map<int, pair<string, int>> cust; 
    // {start station, end station} -> {sum of all time taken by each customer, num of customers}
    map<pair<string, string>, pair<int, int>> stat;

public:
    UndergroundSystem() {
        cust.clear();
        stat.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        cust[id] = {stationName, t}; // customerId -> {startStation, startTime}
    }
    
    void checkOut(int id, string stationName, int t) {
        auto curr = cust[id]; // {startStation, startTime}
        // using call by reference to avoid updating the map again
        auto &curr2 = stat[{curr.first, stationName}]; // {startStation, endStation}
        curr2.first += t - curr.second; // sum += endTime - startTime
        curr2.second++; // people++
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto curr = stat[{startStation, endStation}]; // {sum, people}
        return (double)curr.first/curr.second; // sum/people
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */