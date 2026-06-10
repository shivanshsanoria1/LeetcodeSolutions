class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    bool scoreBalance(string s) {
        int totalScore = 0;
        for(char ch: s)
            totalScore += ch - 'a' + 1;
        
        int score = 0;
        for(char ch: s){
            score += ch - 'a' + 1;
            if(score == totalScore - score)
                return true;
        }

        return false;
    }
};