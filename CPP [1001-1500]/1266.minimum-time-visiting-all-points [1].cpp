class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int dist = 0;
        for(int i=1; i<points.size(); i++)
        {
            int x1 = points[i-1][0], y1 = points[i-1][1];
            int x2 = points[i][0], y2 = points[i][1];
            dist += max(abs(x1 - x2), abs(y1- y2));
        }
        return dist;
    }
};
/*
# it takes 1 sec to move in horizontal (1 unit dist), vertical (1 unit dist) or
  diagonal (sqrt(2) unit dist) direction
# to move from point (x1,y1) to (x2,y2) in min time we should prefer to move digonally 
  for as far as possible and then move horizontal or verical
# so the optimal path is- 
  (x1,y1) --diagonally--> (xd,yd) --horizontal/verical--> (x2,y2)
  where xd = x2 or yd = y2
*/