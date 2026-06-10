class Solution {
public:
    int binaryGap(int n) {
        vector<bool> bits;
        while(n > 0)
        {
            if(n % 2 == 0) // bit-0
                bits.push_back(false);
            else // bit-1
                bits.push_back(true);
            n /= 2;
        }
        
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