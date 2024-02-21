class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2) // 0 mismatch found
            return true;
        // index where chars of s1 and s2 don't match
        int idx1 = -1, idx2 = -1;
        for(int i=0; i<s1.length(); i++)
        {
            if(s1[i] == s2[i])
                continue;
            if(idx1 == -1) // 1st mismatch found
                idx1 = i;
            else if(idx2 == -1) // 2nd mismatch found
                idx2 = i;
            else // 3rd mismatch found
                return false;
        }
        if(idx2 == -1) // only 1 mismatch found
            return false;
        return s1[idx1] == s2[idx2] && s1[idx2] == s2[idx1] ? true : false;
    }
};