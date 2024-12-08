class Solution {
private:
    // returns true if the intervals [s1, e1] and [s2, e2]
    // are non-overlapping
    bool areNonOverlapping(int s1, int e1, int s2, int e2){
        return e1 < s2 || e2 < s1;
    }

public:
    // T.C.=O(n^2), S.C.=O(1)
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        int maxSum = 0;

        for(int i=0; i<n; i++)
        {
            int s1 = events[i][0], e1 = events[i][1];
            int val1 = events[i][2];
            maxSum = max(maxSum, val1);

            for(int j=i+1; j<n; j++)
            {
                int s2 = events[j][0], e2 = events[j][1];
                int val2 = events[j][2];

                if(areNonOverlapping(s1, e1, s2, e2))
                    maxSum = max(maxSum, val1 + val2);
            }
        }

        return maxSum;
    }
};