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
    int findComplement(int num) {
        return binaryStringToInvertedDecimal(decimalToBinaryString(num));
    }
};

// similar: [1009. complement-of-base-10-intege]