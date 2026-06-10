class Solution {
public:
    // T.C.=O(n*26), S.C.=O(1)
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        long long int minCost = 0;

        for(int i=0; i<s.length(); i++)
        {
            long long int costForward = 0;
            for(int j = s[i] - 'a'; j != t[i] - 'a'; j = (j + 1) % 26)
                costForward += nextCost[j];
            
            long long int costBackward = 0;
            for(int j = s[i] - 'a'; j != t[i] - 'a'; j = (j - 1 + 26) % 26)
                costBackward += previousCost[j];   

            minCost += min(costForward, costBackward);
        }

        return minCost;
    }
};