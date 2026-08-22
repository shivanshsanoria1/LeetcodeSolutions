class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int countValidPrefixes(string s) {
        int zeros = 0, ones = 0;
        int count = 0;
        for(char ch: s){
            if(ch == '0')
                zeros++;
            else // ch == '1'
                ones++;
            
            if(abs(zeros - ones) <= 1)
                count++;
        }

        return count;
    }
};