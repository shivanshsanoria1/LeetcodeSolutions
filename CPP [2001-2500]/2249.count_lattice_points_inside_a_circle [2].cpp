class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        unordered_set<string> points;
        for(auto& circle: circles)
        {
            int cx = circle[0];
            int cy = circle[1];
            int r = circle[2];
            
            for(int i=0; i<=r; i++)
                for(int j=0; j<=r; j++)
                    if(i*i + j*j <= r*r)
                    {
                        points.insert(to_string(cx + i) + "#" + to_string(cy + j));
                        points.insert(to_string(cx - i) + "#" + to_string(cy + j));
                        points.insert(to_string(cx - i) + "#" + to_string(cy - j));
                        points.insert(to_string(cx + i) + "#" + to_string(cy - j));
                    }
        }
        return points.size();
    }
};