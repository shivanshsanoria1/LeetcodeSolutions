class Solution {
public:
    // T.C.=O(n^3), S.C.=O(1)
    int minimumDistance(vector<vector<int>>& points) {
        int n=points.size();
        int minDist = INT_MAX;

        for(int e=0; e<n; e++)
        {
            int dist = 0;

            for(int i=0; i<n-1; i++)
            {
                if(e == i)
                    continue;

                int x1 = points[i][0], y1 = points[i][1];

                for(int j=i+1; j<n; j++)
                {
                    if(e == j)
                        continue;

                    int x2 = points[j][0], y2 = points[j][1];

                    dist = max(dist, abs(x1-x2) + abs(y1-y2));
                }
            }

            minDist = min(minDist, dist);
        }

        return minDist;
    }
};
// point at index 'e' is excluded while calculating manhattan-distance