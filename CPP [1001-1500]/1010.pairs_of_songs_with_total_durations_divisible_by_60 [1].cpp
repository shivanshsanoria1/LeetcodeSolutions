class Solution {
public:
    // T.C.=O(16*n), S.C.=O(n)
    int numPairsDivisibleBy60(vector<int>& time) {
        int count = 0;
        // num -> freq
        unordered_map<int, int> mp;

        for(int num: time)
        {
            for(int total=60; total<=1000; total+=60)
                count += mp[total - num];
            mp[num]++;
        }
        
        return count;
    }
};
/*
# since, time[i] is in range [1, 500]
  so, time[i] + time[j] is in range [2, 1000]
# thus, we only have to check for 
  multiples of 60 in range [2, 1000]
  which are: 
  1*60, 2*60, 3*60, ..., 16*60 
*/