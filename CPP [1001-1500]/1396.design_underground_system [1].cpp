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
        auto curr = cust[id];
        string startStation = curr.first;
        int startTime = curr.second;

        auto curr2 = stat[{startStation, stationName}]; // {startStation, endStation}
        int sum = curr2.first;
        int people = curr2.second;
        
        sum += t - startTime; // endTime - startTime
        people++;
        stat[{startStation, stationName}] = {sum, people}; // {startStation, endStation} -> {sum, people}
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto curr = stat[{startStation, endStation}];
        int sum = curr.first;
        int people = curr.second;
        return (double)sum/people;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */