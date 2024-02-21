class Solution {
private:
    typedef pair<int, vector<int>> PI; // {x^2 + y^2, {x, y}}

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<PI> pq; // max-heap
        for(auto& point: points)
        {
            int x = point[0], y = point[1];
            int dist = x*x + y*y; // square of the distance between (0,0) and (x,y)
            pq.push({dist, {x,y}});
            if(pq.size() > k)
                pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};