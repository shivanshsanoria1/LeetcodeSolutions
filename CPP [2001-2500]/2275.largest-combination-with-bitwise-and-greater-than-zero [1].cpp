class Solution {
public:
    // T.C.=O(24*n), S.C.=O(1)
    int largestCombination(vector<int>& candidates) {
        int ans = 0;
        for(int i=0; i<24; i++)
        {
            int mask = 1 << i;
            int count = 0;
            for(int num: candidates)
                if(num & mask)
                    count++;

            ans = max(ans, count);
        }

        return ans;
    }
};

/*
# just find the maximum count of nums with their ith bit set
# given, 1 <= candidates[i] <= 10^7
# since, 10^7 < 2^24, therefore only 24 bits are required
# 10^3 < 2^10
  10^6 < 2^20 ...(1)
  10 < 2^4    ...(2)
  multiplying (1) and (2), 10^7 < 2^24
# thus, 10^7 requires 24 bits for its binary representation
*/