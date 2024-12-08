class Solution {
private:
    // returns the index of the 1st interval whose start-val > e1
    // and -1 if no such interval is found
    int findFirstIdx(vector<vector<int>>& events, int e1){
        int left = 0, right = events.size() - 1;
        int idx = -1;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            int s2 = events[mid][0];

            if(e1 < s2)
            {
                idx = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }

        return idx;
    }

public:
    // T.C.=O(n*log(n)), S.C.=O(n)
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());

        int n = events.size();

        vector<int> suffixMax(n);
        suffixMax[n-1] = events[n-1][2];
        for(int i=n-2; i>=0; i--)
            suffixMax[i] = max(suffixMax[i+1], events[i][2]);

        int maxSum = 0;
        for(int i=0; i<n; i++)
        {
            int s1 = events[i][0], e1 = events[i][1];
            int val1 = events[i][2];
            maxSum = max(maxSum, val1);

            int idx = findFirstIdx(events, e1);
            if(idx != -1)
                maxSum = max(maxSum, val1 + suffixMax[idx]);
        }

        return maxSum;
    }
};