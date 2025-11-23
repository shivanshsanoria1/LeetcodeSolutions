class Solution {
public:
    // T.C.=O(n*logn + n*logk), S.C.=O(n + k)
    // Greedy
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n=quality.size();
        // { wage[i]/quality[i], quality[i] }
        vector<pair<double, int>> ratios(n);

        for(int i=0; i<n; i++)
            ratios[i] = { (double)wage[i]/quality[i], quality[i] };

        // sort in increasing order of wage-to-quality ratio
        sort(ratios.begin(), ratios.end());

        int totalQuality = 0;
        priority_queue<double> pq; // map-heap

        double minCost = DBL_MAX;

        for(auto [currRatio, currQuality]: ratios)
        {
            pq.push(currQuality);
            totalQuality += currQuality;

            if(pq.size() == k+1)
            {
                int maxQuality = pq.top();
                pq.pop();
                totalQuality -= maxQuality;
            }
            
            if(pq.size() == k)
                minCost = min(minCost, currRatio * totalQuality);
        }

        return minCost;
    }
};