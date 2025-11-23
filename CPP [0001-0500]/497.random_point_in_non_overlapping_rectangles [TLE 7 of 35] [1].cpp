class Solution {
private:
    vector<vector<int>> points;

public:
    Solution(vector<vector<int>>& rects) {
        for(vector<int>& rect: rects)
        {
            int x1 = rect[0];
            int y1 = rect[1];
            int x2 = rect[2];
            int y2 = rect[3];

            for(int i=x1; i<=x2; i++)
                for(int j=y1; j<=y2; j++)
                    points.push_back({i, j});
        }

        // use curr time as seed for random generator 
        srand(time(0));
    }
    
    vector<int> pick() {
        return points[rand() % points.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */