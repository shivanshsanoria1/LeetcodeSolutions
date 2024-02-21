class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end()); // sort intervals by start value
        int count = 1;
        int prevEnd = points[0][1];
        for(int i=1; i<points.size(); i++)
        {
            int currStart = points[i][0], currEnd = points[i][1];
            if(currStart <= prevEnd) // intervals overlap
                // take the interval with smaller end point as it is less likely 
                // to overlap with the next intervals
                prevEnd = min(prevEnd, currEnd);
            else // intervals don't overlap
            {
                count++;
                prevEnd = currEnd; // update the prev end
            }
        }
        return count;
    }
};
// similar to Leetcode-435 non overlapping intervals