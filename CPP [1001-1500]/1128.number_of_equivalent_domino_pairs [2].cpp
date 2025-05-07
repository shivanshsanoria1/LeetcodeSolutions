class Solution {
public:
    // T.C.=O(n + 100), S.C.=O(100)
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        // 10x10 grid filled with 0's
        vector<vector<int>> freq(10, vector<int>(10, 0)); 
        for(vector<int>& domino: dominoes)
        {
            int a = domino[0], b = domino[1];
            freq[a][b]++;
        }

        int count = 0;
        for(int i=1; i<=9; i++)
            for(int j=i; j<=9; j++)
            {
                int pairs = i == j ? freq[i][j] : freq[i][j] + freq[j][i];
                // x equivalent elements will generate xC2= (x*(x-1))/2 pairs
                count += (pairs*(pairs-1)) / 2;
            }

        return count;
    }
};