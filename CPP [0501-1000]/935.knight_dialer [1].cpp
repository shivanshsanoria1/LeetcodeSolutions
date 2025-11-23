class Solution {
private:
    #define MOD int(1e9 + 7)

public:
    int knightDialer(int n) { // T.C.=O(10*n), S.C.=O(1)
        // mp[i][j]: next reachable spot from the ith spot
        vector<vector<int>> mp = {{4,6}, {6,8}, {7,9}, {4,8}, {0,3,9}, {}, {0,1,7}, {2,6}, {1,3}, {2,4}};
        // for n = 1, only 1 way to reach each spot
        vector<int> prevRow(10, 1);
        // for n >= 2, initially 0 ways to reach each spot
        vector<int> currRow(10, 0);
        
        while(--n) // repeat for (n-1) times
        {
            for(int i=0; i<=9; i++)
            {
                if(i == 5)
                    continue;
                for(int j=0; j<mp[i].size(); j++)
                    currRow[i] = (currRow[i] + prevRow[mp[i][j]]) % MOD;
            }

            for(int i=0; i<=9; i++)
            {
                // curr row becomes the prev row for the next iteration
                prevRow[i] = currRow[i];
                // clear the curr row for the next iteration
                currRow[i] = 0;
            }
        }

        int ans = 0;
        for(int i=0; i<=9; i++)
            ans = (ans + prevRow[i]) % MOD;
        return ans;
    }
};