class Solution {
public:
    // T.C.=O(n), S.C.=O(60)
    int numPairsDivisibleBy60(vector<int>& time) {
        int count = 0;
        vector<int> freq(60, 0);

        for(int num: time)
        {
            int mod = num % 60;
            count += mod == 0 ? freq[0] : freq[60 - mod];
            freq[mod]++;
        }
        
        return count;
    }
};
/*
# reduce all nums mod 60 to get them in range [0, 59]
# in general, (a + b) is divisible by M (here, M = 60) when either
  # (a % M == 0) and (b % M == 0)
    or
  # (a % M == x) and (b % M == M-x)

# similar: [3185. count-pairs-that-form-a-complete-day-ii]
*/