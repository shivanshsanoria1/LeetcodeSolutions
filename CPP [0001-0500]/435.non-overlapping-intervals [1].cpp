class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) { // Greedy, T.C.=O(n*logn)
        sort(intervals.begin(), intervals.end()); // sort intervals by start value
        int remove = 0;
        int prevEnd = intervals[0][1];
        for(int i=1; i<intervals.size(); i++)
        {
            int currStart = intervals[i][0], currEnd = intervals[i][1];
            if(currStart < prevEnd) // intervals overlap
            {
                remove++;
                // take the interval with smaller end point as it is less likely 
                // to overlap with the next intervals
                prevEnd = min(prevEnd, currEnd);
            }
            else // intervals touch or don't overlap
                prevEnd = currEnd; // update the prev end
        }
        return remove;
    }
};