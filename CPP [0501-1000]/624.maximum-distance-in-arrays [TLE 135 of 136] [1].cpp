class Solution {
public:
    // T.C.=O(m^2), S.C.=O(1)
    int maxDistance(vector<vector<int>>& arrays) {
        int m=arrays.size();
        int maxDist = 0;

        for(int i=0; i<m-1; i++)
        {
            int min1 = arrays[i][0];
            int max1 = arrays[i].back();
            
            int min2 = INT_MAX;
            int max2 = INT_MIN;

            for(int j=i+1; j<m; j++)
            {
                min2 = min(min2, arrays[j][0]);
                max2 = max(max2, arrays[j].back());
            }

            maxDist = max(maxDist, abs(min1 - max2));
            maxDist = max(maxDist, abs(max1 - min2));
        }

        return maxDist;
    }
};