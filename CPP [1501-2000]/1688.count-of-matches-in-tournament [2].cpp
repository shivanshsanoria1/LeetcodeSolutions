class Solution {
public:
    int numberOfMatches(int n) {
        return n-1;
    }
};
// at the end only 1 team wins, ie, (n-1) teams are eliminated, 
// but each elimination requires a match, ie, (n-1) matches