class Solution {
public:
    // T.C.=O(q*n), S.C.=O(1)
    // q: size of queries[], n: size of points[]
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;

        for(vector<int>& query: queries)
        {
            int x0 = query[0];
            int y0 = query[1];
            int r = query[2];

            int count = 0;

            for(vector<int>& point: points)
            {
                int x1 = point[0];
                int y1 = point[1];

                if((x0-x1)*(x0-x1) + (y0-y1)*(y0-y1) <= r*r)
                    count++;
            }

            ans.push_back(count);
        }

        return ans;
    }
};