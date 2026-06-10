class Solution {
private:
    #define MOD int(1e9 + 7)

public:
    // T.C.=O(n), S.C.=O(1)
    // 2-pointer
    int numSub(string s) {
        int left = 0, right = 0;
        int count = 0;
        
        while(right < s.length())
        {
            if(s[right] == '0')
                left = right + 1;
            else
                count = (count + (right - left + 1)) % MOD;
            right++;
        }

        return count;
    }
};