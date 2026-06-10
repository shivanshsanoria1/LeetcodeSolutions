class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int scoreOfString(string s) {
        int score = 0;
        for(int i=1; i<s.length(); i++)
            score += abs(s[i] - s[i-1]);
        return score;
    }
};