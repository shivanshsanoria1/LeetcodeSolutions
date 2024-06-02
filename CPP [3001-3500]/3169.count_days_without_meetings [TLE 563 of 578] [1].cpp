class Solution {
public:
    // T.C.=O(m*days), S.C.=O(days)
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<bool> hasMeeting(days + 1, false);

        for(vector<int>& meeting: meetings)
        {
            int start = meeting[0];
            int end = meeting[1];

            for(int i=start; i<=end; i++)
                hasMeeting[i] = true;
        }

        int freeDays = 0;
        for(int i=1; i<=days; i++)
            if(!hasMeeting[i])
                freeDays++;

        return freeDays;
    }
};