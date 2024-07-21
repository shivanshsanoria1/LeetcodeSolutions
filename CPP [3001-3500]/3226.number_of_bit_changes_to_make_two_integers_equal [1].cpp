class Solution {
private:
    string intToBinStr(int num){
        string str = "";
        while(num > 0)
        {
            str += to_string(num & 1);
            num = num >> 1;
        }

        reverse(str.begin(), str.end());
        string leadingZeros(20 - str.length(), '0');
        return leadingZeros + str;
    }

public:
    int minChanges(int n, int k) {
        string s1 = intToBinStr(n);
        string s2 = intToBinStr(k);

        int ops = 0; // operations
        for(int i=0; i<20; i++)
            if(s1[i] != s2[i])
            {
                if(s1[i] == '1')
                    ops++;
                else // s1[i] == '0'
                    return -1;
            }

        return ops;
    }
};
// given: n, k are in range [1, 10^6]
// since, 10^6 < 2^20
// as, 2^20 is the first num to require 21 bits for its binary representation
// so, 10^6 requires 20 bits for its binary representation