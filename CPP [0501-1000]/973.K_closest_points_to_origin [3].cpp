class Solution {
public:
    // T.C.=O(n*log(k)), S.C.=O(k)
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // max-heap; {x^2 + y^2, x, y}
        priority_queue<vector<int>> pq; 
        for(vector<int>& point: points)
        {
            int x = point[0], y = point[1];
            // square of the distance between (0,0) and (x,y)
            int dist = x*x + y*y; 

            pq.push({dist, x, y});
            if(pq.size() == k+1)
                pq.pop();
        }

        vector<vector<int>> ans;
        while(!pq.empty())
        {
            ans.push_back({pq.top()[1], pq.top()[2]});
            pq.pop();
        }

        return ans;
    }
};