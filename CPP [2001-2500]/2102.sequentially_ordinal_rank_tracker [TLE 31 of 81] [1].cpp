class SORTracker {
private:
    int queryCount = -1;

    vector<pair<int, string>> locations;

    static bool cmp(pair<int, string>& p1, pair<int, string>& p2) {
        auto [score1, name1] = p1;
        auto [score2, name2] = p2;
        return score1 == score2 ? name1 < name2 : score1 > score2;
    }

public:
    SORTracker() {
        this->locations.clear();
    }
    
    void add(string name, int score) {
        this->locations.push_back({score, name});
        sort(this->locations.begin(), this->locations.end(), cmp);
    }
    
    string get() {
        this->queryCount++;
        return this->locations[this->queryCount].second;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */