class Solution {
public:
    // T.C.=O(m), S.C.=O(m)
    int maxDistance(vector<vector<int>>& arrays) {
        int m=arrays.size();
        vector<int> postfixMins(m);
        vector<int> postfixMaxs(m);

        postfixMins[m-1] = arrays[m-1][0];
        postfixMaxs[m-1] = arrays[m-1].back();
        for(int i=m-2; i>=0; i--)
        {
            postfixMins[i] = min(arrays[i][0], postfixMins[i+1]);
            postfixMaxs[i] = max(arrays[i].back(), postfixMaxs[i+1]);
        }

        int maxDist = 0;
        for(int i=0; i<m-1; i++)
        {
            maxDist = max(maxDist, abs(arrays[i][0] - postfixMaxs[i+1]));
            maxDist = max(maxDist, abs(arrays[i].back() - postfixMins[i+1]));
        }

        return maxDist;
    }
};