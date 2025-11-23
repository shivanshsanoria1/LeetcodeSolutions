class Solution {
private:
    typedef vector<int> VI;

public:
    // T.C.=O(n*log(n)), S.C.=O(n)
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // min-heap; {x^2 + y^2, x, y}
        priority_queue<VI, vector<VI>, greater<VI>> pq; 
        for(vector<int>& point: points)
        {
            int x = point[0], y = point[1];
            // square of the distance between (0,0) and (x,y)
            int dist = x*x + y*y; 

            pq.push({dist, x, y});
        }

        vector<vector<int>> ans;
        while(k--)
        {
            int x = pq.top()[1], y = pq.top()[2];
            pq.pop();

            ans.push_back({x, y});
        }

        return ans;
    }
};