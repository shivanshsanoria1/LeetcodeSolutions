class Solution {
public:
    // T.C.=O(n1*n2), S.C.=O(n2)
    // DP: Tabulation (with Space-Optimization)
    int longestCommonSubsequence(string s1, string s2) {
        int n1=s1.length(), n2=s2.length();

        vector<int> dp_prev(n2, 0);
        vector<int> dp_curr(n2, 0);

        for(int i=0; i<n1; i++)
        {
            for(int j=0; j<n2; j++)
            {
                int northWest = i-1 >= 0 && j-1 >= 0 ? dp_prev[j-1] : 0;
                int north = i-1 >= 0 ? dp_prev[j] : 0;
                int west = j-1 >= 0 ? dp_curr[j-1] : 0;
                
                dp_curr[j] = s1[i] == s2[j] ? 1 + northWest : max(north, west);
            }

            dp_prev = dp_curr;
        }
        
        return dp_prev[n2-1];
    }
};