class DetectSquares {
private:
    map<pair<int, int>, int> mp; // {x,y} -> freq 

public:
    DetectSquares() {
        mp.clear();
    }
    
    void add(vector<int> point) {
        mp[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        int ans = 0;
        int x = point[0];
        int y = point[1];
        for(auto it: mp)
        {
            int xk = it.first.first;
            int yk = it.first.second;
            // {x, y} and {xk, yk} are the same points
            if(x == xk || y == yk) 
                continue;
            // {xk, yk} is not on the diagonal to {x, y}
            if(abs(x - xk) != abs(y - yk)) 
                continue;
            // check if both {xk, y} and {x, yk} exist in map
            if(mp.find({xk, y}) != mp.end() && mp.find({x, yk}) != mp.end())
                ans += mp[{xk, yk}] * mp[{xk, y}] * mp[{x, yk}];
        }
        return ans;
    }
};
/*
# num of squares formed from {x, y}, {xk, yk}, {xk, y}, {x, yk} is 
  the product of freqs of {xk, yk}, {xk, y}, {x, yk}
*/

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */