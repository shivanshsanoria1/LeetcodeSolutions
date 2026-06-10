class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int min_dis=INT_MAX, min_index=-1;
        for(int i=0; i<points.size(); i++)
        {
            if(x == points[i][0] || y == points[i][1]) //valid point found
            {
                int dis= abs(x-points[i][0]) + abs(y-points[i][1]);
                if(dis < min_dis) //new min distance found
                {
                    min_dis=dis; //update min distance
                    min_index=i; //store index of point with min distance
                }
            }
        }
        return min_index;
    }
};