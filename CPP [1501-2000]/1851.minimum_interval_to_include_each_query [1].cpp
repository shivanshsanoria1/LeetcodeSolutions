class Solution {
private:
    typedef pair<int, int> PI;

public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n=intervals.size(), q=queries.size();
        vector<int> ans(q);

        sort(intervals.begin(), intervals.end());
        vector<PI> points; // {query, index}
        for(int i=0; i<q; i++)
            points.push_back({queries[i], i});
        sort(points.begin(), points.end());

        priority_queue<PI, vector<PI>, greater<PI>> pq; // min-heap
        int i = 0; // index i to iterate over intervals[]
        for(auto& [point, idx]: points)
        {
            // push the intervals whose start point <= curr point
            while(i < n && intervals[i][0] <= point)
            {
                // {end - start + 1, end}
                pq.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                i++;
            }
            // pop out the intervals whose end point < curr point
            while(!pq.empty() && pq.top().second < point)
                pq.pop();
            // idx gets the original index of curr point in queries[]
            // if heap is empty, then there is no interval in which curr point lies
            ans[idx] = !pq.empty() ? pq.top().first : -1;
        }
        return ans;
    }
};
// T.C.=O(n*logn + q*logq), S.C.=O(n + q), n: length of intervals[], q: length of queries[]