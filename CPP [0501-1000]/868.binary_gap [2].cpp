class Solution {
public:
    int binaryGap(int n) {
        bitset<32> bits(n);
        int prevIdx = -1;
        int ans = 0;
        for(int i=0; i<bits.size(); i++)
        {
            if(!bits[i]) // skip the 0 bits
                continue;
            if(prevIdx != -1)
                ans = max(ans, i - prevIdx);
            prevIdx = i;
        }
        return ans;
    }
};