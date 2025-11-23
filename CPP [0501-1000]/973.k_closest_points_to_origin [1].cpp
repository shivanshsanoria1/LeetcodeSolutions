class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(n)
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> temp;
        for(vector<int>& point: points)
        {
            int x = point[0], y = point[1];
            // square of the distance between (0,0) and (x,y)
            int dist = x*x + y*y; 

            temp.push_back({dist, x, y});
        }

        sort(temp.begin(), temp.end());

        vector<vector<int>> ans;
        for(int i=0; i<k; i++)
        {
            int x = temp[i][1], y = temp[i][2];
            ans.push_back({x, y});
        }

        return ans;
    }
};