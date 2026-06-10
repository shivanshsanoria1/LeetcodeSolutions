class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int minLengthAfterRemovals(string s) {
        int countA = count(s.begin(), s.end(), 'a');
        int countB = s.length() - countA;
        
        return abs(countA - countB);
    }
};