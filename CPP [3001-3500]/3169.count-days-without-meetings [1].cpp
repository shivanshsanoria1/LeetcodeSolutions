class Solution {
public:
    // T.C.=O(m*logm), S.C.=O(1)
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        // days with no meetings
        int freeDays = 0;

        int prevStart = meetings[0][0];
        int prevEnd =  meetings[0][1];
        
        for(int i=1; i<meetings.size(); i++)
        {
            int currStart = meetings[i][0];
            int currEnd = meetings[i][1];

            // no overlap between prev and curr intervals
            if(prevEnd < currStart)
                freeDays += currStart - prevEnd - 1;
            
            // merge the prev and curr intervals
            prevStart = min(prevStart, currStart);
            prevEnd = max(prevEnd, currEnd);
        }

        // free days before the smallest start-time of any meeting
        freeDays += meetings[0][0] - 1;
        // free days after the largest end-time of any meeting
        freeDays += days - prevEnd;

        return freeDays;
    }
};