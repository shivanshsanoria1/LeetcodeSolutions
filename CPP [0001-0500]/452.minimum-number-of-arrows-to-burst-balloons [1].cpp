class Solution {
public:
    // T.C.=O(n*logn), S.C.=O(1)
    int findMinArrowShots(vector<vector<int>>& points) {
        // sort intervals in increasing order of start value
        sort(points.begin(), points.end()); 

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
                // update the prev end
                prevEnd = currEnd; 
            }
        }
        return count;
    }
};
// similar to [435. non overlapping intervals]