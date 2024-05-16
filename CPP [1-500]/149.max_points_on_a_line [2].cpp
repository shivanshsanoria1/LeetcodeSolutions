class Solution {
public:
    // T.C.=O(n^2), S.C.=O(n)
    int maxPoints(vector<vector<int>>& points) { 
        int n=points.size();

        if(n < 3)
            return n;

        int ans = 0;

        for(int i=0; i<n-1; i++)
        {
            // slope -> freq
            unordered_map<float, int> mp; 
            int x1 = points[i][0], y1 = points[i][1];

            for(int j=i+1; j<n; j++)
            {
                int x2 = points[j][0], y2 = points[j][1];

                float slope = x2-x1 == 0 ? INT_MAX : (float)(y2-y1)/(x2-x1);
                mp[slope]++;

                // +1 is done to include the ith point
                ans = max(ans, 1 + mp[slope]);
            }
        }

        return ans;
    }
};
/*
# assume the ith point A(x1, y1) lies on the required line, 
  ie, line with max points lying on it
# use the jth point B(x2, y2) to calculate the slope of the line AB
# add the slope and its freq to a map and find the max freq for each ith point
*/
