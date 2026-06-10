class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // keeps track of who can be the judge, initially all people can be the judge
        vector<bool> isJudge(n+1, true);
        // keeps track of num of people who trust the person at index i, initially 0
        vector<int> trustCount(n+1, 0); 
        for(int i=0; i<trust.size(); i++)
        {
            isJudge[trust[i][0]] = false; // trust[i][0] cannot be the judge, as he trusts someone
            trustCount[trust[i][1]]++; // increment count of people who trust the person trust[i][1]
        }
        for(int i=1; i<=n; i++)
            if(isJudge[i] == true && trustCount[i] == n-1) //judge found
                return i;
        return -1;
    }
};