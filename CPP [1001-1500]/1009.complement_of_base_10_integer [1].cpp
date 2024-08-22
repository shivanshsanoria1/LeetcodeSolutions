class Solution {
private:
    string decimalToBinaryString(int num){
        string str = "";
        while(num > 0)
        {
            str += to_string(num & 1);
            num >>= 1;
        }

        reverse(str.begin(), str.end());
        return str;
    }

    int binaryStringToInvertedDecimal(string str){
        int num = 0;
        for(char ch: str)
        {
            num <<= 1;
            num |= ch == '0' ? 1 : 0;
        }

        return num;
    }   

public:
    // Bit-manipulation
    int bitwiseComplement(int n) {
        if(n == 0)
            return 1;

        return binaryStringToInvertedDecimal(decimalToBinaryString(n));
    }
};

// similar: [476. number-complement]