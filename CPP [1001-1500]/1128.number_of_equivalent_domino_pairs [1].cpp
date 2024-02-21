class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n=dominoes.size(), ans=0;
        vector<vector<int>> grid(10,vector<int>(10,0)); //10x10 grid filled with 0's
        for(int i=0; i<n; i++)
            grid[dominoes[i][0]][dominoes[i][1]]++;
        for(int i=1; i<10; i++) //no use for 0th row as 1<=dominos[a][b]<=9
            for(int j=i; j<10; j++) //loop for diagonal and upper-diagonal elements
            {
                int pairs;
                if(i!=j) //non-diagonal elements
                    pairs=grid[i][j]+grid[j][i];
                else //diagonal elements
                    pairs=grid[i][j];
                if(pairs > 1) //x equivalent pairs will generate xC2= ((x-1)*x)/2 pairs of pairs
                    ans+=((pairs-1)*pairs)/2;
            }
        return ans;
    }
};