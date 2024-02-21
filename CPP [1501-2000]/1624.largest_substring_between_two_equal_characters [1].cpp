class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) { // T.C.=O(n^2), S.C.=O(1)
        int n=s.length();
        int ans = -1;
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
            {
                if(s[i] != s[j])
                    continue;
                ans = max(ans, j-i-1);
            }
        return ans;
    }
};