class Solution {
private:
    typedef pair<int, int> PII;

public:
    // T.C.=O(n*log(n)), S.C.=O(n)
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());

        // min-heap; {end-time, val}
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        int maxSum = 0;
        int maxVal2 = 0;

        for(vector<int>& event: events)
        {
            int s1 = event[0], e1 = event[1];
            int val1 = event[2];

            // pop out the intervals whose end-time < curr start-time
            // and find the max-val among them
            while(!pq.empty() && pq.top().first < s1)
            {
                maxVal2 = max(maxVal2, pq.top().second);
                pq.pop();
            }

            maxSum = max(maxSum, val1 + maxVal2);
            pq.push({e1, val1});
        }

        return maxSum;
    }
};