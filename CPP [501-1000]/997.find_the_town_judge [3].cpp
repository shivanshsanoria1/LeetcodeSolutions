class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> degree(n+1, 0); 
        for(int i=0; i<trust.size(); i++)
        {
            degree[trust[i][0]]--;
            degree[trust[i][1]]++;
        }
        for(int i=1; i<=n; i++)
            if(degree[i] == n-1) // judge found
                return i;
        return -1;
    }
};
// the judge trusts 0 people and is trusted by (n-1) people
// [a,b]: a -> b: means a trusts b, degree-- for a and degree++ for b