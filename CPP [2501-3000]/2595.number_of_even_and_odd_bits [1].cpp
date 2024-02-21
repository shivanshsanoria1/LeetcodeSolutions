class Solution {
public:
    vector<int> evenOddBit(int n) {
        string bin = bitset<32>(n).to_string(); // int to binary string of length 32
        int pos = 0;
        int evenCount = 0, oddCount = 0;
        for(int i=bin.length()-1; i>=0; i--, pos++)
        {
            if(bin[i] == '0') // skip the 0's
                continue;
            if(pos % 2 == 0) // even position
                evenCount++;
            else // odd position
                oddCount++;
        }
        return {evenCount, oddCount};
    }
};
// indexes are 0,1,2,... from LSB -> MSB