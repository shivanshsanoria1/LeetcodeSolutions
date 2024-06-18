class Solution {
public:
    // T.C.=O(n), S.C.=O(24)
    long long countCompleteDayPairs(vector<int>& hours) {
        vector<int> freq(24, 0);
        long long int count = 0;

        for(int hour: hours)
        {
            int mod = hour % 24;
            count += mod == 0 ? freq[0] : freq[24 - mod];
            freq[mod]++;
        }
        
        return count;
    }
};
/*
# reduce all nums mod 24 to get them in range [0, 23]
# in general, (a + b) is divisible by M (here, M = 24) when either
  # (a % M == 0) and (b % M == 0)
    or
  # (a % M == x) and (b % M == M-x)

# similar: [1010. pairs-of-songs-with-total-durations-divisible-by-60]
*/