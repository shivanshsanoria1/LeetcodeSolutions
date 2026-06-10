class Solution {
public:
    int minimumMoves(string s) {
        int count = 0;
        int i = 0;
        while(i < s.length())
        {
            if(s[i] == 'O')
                i++;
            else // s[i] == 'X'
            {
                count++;
                i += 3;
            }
        }
        return count;
    }
};