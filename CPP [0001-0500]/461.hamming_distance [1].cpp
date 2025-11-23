class Solution {
private:
    string convertIntToBinString(int num){
        string binStr = "";
        while(num > 0)
        {
            binStr += num & 1 ? "1" : "0";
            num >>= 1;
        }

        string leadingZeros = string(31 - binStr.length(), '0');
        binStr += leadingZeros;

        reverse(binStr.begin(), binStr.end());

        return binStr;
    }

public:
    int hammingDistance(int x, int y) {
        string s1 = convertIntToBinString(x);
        string s2 = convertIntToBinString(y);

        int count = 0;
        for(int i=0; i<31; i++)
            if(s1[i] != s2[i])
                count++;
        
        return count;
    }
};

// similar: [2220. minimum-bit-flips-to-convert-number]