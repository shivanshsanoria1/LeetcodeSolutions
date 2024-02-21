class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        unordered_set<string> points;
        for(auto& circle: circles)
        {
            int cx = circle[0];
            int cy = circle[1];
            int r = circle[2];
            
            for(int i=-r; i<=r; i++)
                for(int j=-r; j<=r; j++)
                {
                    int x1 = cx + i;
                    int y1 = cy + j;
                    if((x1-cx)*(x1-cx) + (y1-cy)*(y1-cy) <= r*r)
                        points.insert(to_string(x1) + "#" + to_string(y1));
                }
        }
        return points.size();
    }
};