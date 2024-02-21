class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    long long minimumSteps(string s) {
        int idx = 0;
        long long int swaps = 0;
        for(int i=0; i<s.length(); i++)
            if(s[i] == '0')
            {
                swaps += i - idx;
                idx++;
            }
        return swaps;
    }
};