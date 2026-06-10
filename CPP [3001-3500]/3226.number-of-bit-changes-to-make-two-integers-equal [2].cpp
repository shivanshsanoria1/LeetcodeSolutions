class Solution {
public:
    int minChanges(int n, int k) {
        int ops = 0; // operations
        while(n > 0 || k > 0)
        {
            int bit1 = n & 1;
            int bit2 = k & 1;

            if(bit1 != bit2)
            {
                if(bit1 == 1)
                    ops++;
                else // bit1 == 0
                    return -1;
            }

            n = n >> 1;
            k = k >> 1;
        }

        return ops++;
    }
};