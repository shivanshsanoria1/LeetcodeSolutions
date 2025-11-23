class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // keeps track of num of people the ith person trusts, initially 0
        vector<int> trusts(n+1, 0); 
        // keeps track of num of people who trust the ith person, initially 0
        vector<int> trustedBy(n+1, 0); 
        for(int i=0; i<trust.size(); i++)
        {
            trusts[trust[i][0]]++;
            trustedBy[trust[i][1]]++;
        }
        for(int i=1; i<=n; i++)
            if(trusts[i] == 0 && trustedBy[i] == n-1) // judge found
                return i;
        return -1;
    }
};
// the judge trusts 0 people and is trusted by (n-1) people