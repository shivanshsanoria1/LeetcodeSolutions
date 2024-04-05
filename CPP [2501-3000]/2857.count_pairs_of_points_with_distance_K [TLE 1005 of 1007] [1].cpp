class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int countPairs(vector<vector<int>>& coordinates, int k) {
        int n=coordinates.size();
        int count = 0;

        for(int i=0; i<n-1; i++)
        {
            int x1 = coordinates[i][0], y1 = coordinates[i][1];

            for(int j=i+1; j<n; j++)
            {
                int x2 = coordinates[j][0], y2 = coordinates[j][1];

                if((x1^x2) + (y1^y2) == k)
                    count++;
            }   
        }

        return count;
    }
};