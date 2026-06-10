class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    long long maxArea(vector<vector<int>>& coords) {
        int minX = INT_MAX, maxX = INT_MIN;
        int minY = INT_MAX, maxY = INT_MIN;
        
        // x-coord -> {min y-coord, max y-coord}
        unordered_map<int, pair<int, int>> mpX;
        // y-coord -> {min x-coord, max x-coord}
        unordered_map<int, pair<int, int>> mpY;

        for(vector<int>& coord: coords)
        {
            int x = coord[0], y = coord[1];

            minX = min(minX, x);
            maxX = max(maxX, x);

            minY = min(minY, y);
            maxY = max(maxY, y);

            if(mpX.find(x) == mpX.end())
                mpX[x] = {y, y};
            else
            {
                mpX[x].first = min(mpX[x].first, y);
                mpX[x].second = max(mpX[x].second, y);
            }
            
            if(mpY.find(y) == mpY.end())
                mpY[y] = {x, x};
            else
            {
                mpY[y].first = min(mpY[y].first, x);
                mpY[y].second = max(mpY[y].second, x);
            }
        }

        // max-area * 2
        long long int maxArea2 = -1;
        
        for(auto it: mpX)
        {
            int x = it.first;
            auto [y1, y2] = it.second;

            int base = y2 - y1;
            if(base == 0)
                continue;

            long long int maxHeight = max(x - minX, maxX - x);
            if(maxHeight == 0)
                continue;
            
            maxArea2 = max(maxArea2, maxHeight * base);
        }

        for(auto it: mpY)
        {
            int y = it.first;
            auto [x1, x2] = it.second;

            int base = x2 - x1;
            if(base == 0)
                continue;

            long long int maxHeight = max(y - minY, maxY - y);
            if(maxHeight == 0)
                continue;
            
            maxArea2 = max(maxArea2, maxHeight * base);
        }

        return maxArea2;
    }
};