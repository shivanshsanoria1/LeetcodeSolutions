class Solution {
private:
    #define MOD int(1e9 + 7)

public:
    // T.C.=O(n^2), S.C.=O(1)
    int numSub(string s) {
        int n=s.length();
        int count = 0;

        for(int i=0; i<n; i++)
            for(int j=i; j<n; j++)
            {
                if(s[j] == '0')
                    break;
                count = (count + 1) % MOD;
            }
        
        return count;
    }
};