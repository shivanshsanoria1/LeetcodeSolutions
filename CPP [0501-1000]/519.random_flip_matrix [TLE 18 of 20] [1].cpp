class Solution {
private:
    int m = 0, n = 0;
    unordered_set<string> unvisited;

public:
    // T.C.=O(m*n), S.C.=O(m*n)
    Solution(int m, int n) {
        // store the dimensions of grid
        this->m = m;
        this->n = n;

        // initially all points are unvisited
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                this->unvisited.insert(to_string(i) + "#" + to_string(j));

        // use the current time as seed for random generator 
        srand(time(0));
    }
    
    // T.C.=O(m*n), S.C.=O(1)
    vector<int> flip() {
        // generate a random index for the unvisited set
        int randIdx = rand() % this->unvisited.size();
        // iterator to the start of the set
        auto itr = this->unvisited.begin();
        // move the iterator 'randIdx' places forward
        while(randIdx--)
            itr++;
        
        // extract the coordinates of the point 
        // pointed by the iterator
        string point = *itr;
        int splitIdx = point.find('#');
        int i = stoi(point.substr(0, splitIdx));
        int j = stoi(point.substr(splitIdx + 1));

        // mark the point pointed by the iterator
        // as visited by removing it from the set
        this->unvisited.erase(itr);

        return {i, j};
    }
    
    // T.C.=O(m*n), S.C.=O(1)
    void reset() {
        // mark all points as unvisited
        for(int i=0; i<this->m; i++)
            for(int j=0; j<this->n; j++)
                this->unvisited.insert(to_string(i) + "#" + to_string(j));
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */