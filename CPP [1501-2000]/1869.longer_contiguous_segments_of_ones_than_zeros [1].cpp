class Solution {
public:
    bool checkZeroOnes(string s) {
        int zeros = 0, ones = 0;
        int longestZeros = 0, longestOnes = 0;
        for(char ch: s)
        {
            if(ch == '0')
            {
                zeros++;
                longestZeros = max(longestZeros, zeros);
                ones = 0;
            }
            else // ch == '1'
            {
                ones++;
                longestOnes = max(longestOnes, ones);
                zeros = 0;
            }
        }
        return longestOnes > longestZeros ? true : false;
    }
};