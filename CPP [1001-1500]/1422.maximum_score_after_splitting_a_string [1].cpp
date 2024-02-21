class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int maxScore(string s) {
        int leftZeros = 0;
        int rightOnes = count(s.begin(), s.end(), '1');
        int ans = 0;
        for(int i=0; i<s.length()-1; i++)
        {
            if(s[i] == '0')
                leftZeros++;
            else
                rightOnes--;
            ans = max(ans, leftZeros + rightOnes);
        }
        return ans;
    }
};