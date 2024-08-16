class DetectSquares {
private:
    // hash of point -> freq
    unordered_map<string, int> mp;

    string getHash(int x, int y){
        return to_string(x) + "#" + to_string(y);
    }

    pair<int, int> getPointFromHash(string hash){
        int idx = hash.find("#");
        int x = stoi(hash.substr(0, idx));
        int y = stoi(hash.substr(idx + 1));

        return {x, y};
    }

public:
    DetectSquares() {
        this->mp.clear();
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        mp[getHash(x, y)]++;
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int ans = 0;

        for(auto [hash, freq]: mp)
        {
            auto [xk, yk] = getPointFromHash(hash);
            
            // {x, y} and {xk, yk} are the same points
            if(x == xk || y == yk) 
                continue;
            // {xk, yk} is not on the diagonal to {x, y}
            if(abs(x - xk) != abs(y - yk)) 
                continue;
            
            string hash1 = getHash(xk, y);
            string hash2 = getHash(x, yk);

            // check if both the points {xk, y} and {x, yk} exist in map
            if(mp.find(hash1) != mp.end() && mp.find(hash2) != mp.end())
                ans += mp[hash] * mp[hash1] * mp[hash2];
        }

        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */

/*
(x,yk) - (xk,yk) 
  |         |
(x,y)  - (xk,y)

# num of squares formed with the points: 
  {x, y}, {xk, yk}, {xk, y}, {x, yk} is the
  product of freqs of {xk, yk}, {xk, y}, {x, yk}
*/