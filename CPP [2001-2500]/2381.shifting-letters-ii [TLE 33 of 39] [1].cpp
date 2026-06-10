class Solution {
public:
    // T.C.=O(n1*n2), S.C.=O(1)
    // n1: length of s, n2: size of shifts[]
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        for(vector<int>& shift: shifts)
        {
            int left = shift[0], right = shift[1], dir = shift[2];
            for(int i=left; i<=right; i++)
            {
                int val = dir == 1 ? (s[i] - 'a' + 1) % 26 : (s[i] - 'a' - 1 + 26) % 26;
                s[i] = 'a' + val;
            }
        }

        return s;
    }
};