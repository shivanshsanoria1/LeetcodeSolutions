class Solution {
public:
    vector<int> evenOddBit(int n) {
        int evenCount = 0, oddCount = 0;
        bool pos = false; // false: even, true: odd
        while(n > 0)
        {
            if(n & 1 == 1) // last bit is set
            {
                if(!pos) // even position
                    evenCount++;
                else // odd position
                    oddCount++;
            }
            pos = !pos;
            n = n >> 1; // discard the last bit
        }
        return {evenCount, oddCount};
    }
};
// indexes are 0,1,2,... from LSB -> MSB