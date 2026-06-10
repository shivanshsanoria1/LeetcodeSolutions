class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    int longestWPI(vector<int>& hours) {
        int prefixSum = 0;
        int maxLen = 0;
        // prefixSum (which is <= 0) -> index of 1st occurence
        unordered_map<int, int> mp;

        for(int i=0; i<hours.size(); i++)
        {
            prefixSum += hours[i] > 8 ? 1 : -1;

            // subarray in index-range [0, i] is valid
            if(prefixSum > 0)
            {
                maxLen = i+1;
                continue;
            }

            // (prefixSum - 1) found in map
            // subarray in index-range [mp[prefixSum - 1], i] is valid
            if(mp.find(prefixSum - 1) != mp.end())
                maxLen = max(maxLen, i - mp[prefixSum - 1]);

            // curr prefixSum not found in map
            if(mp.find(prefixSum) == mp.end())
                mp[prefixSum] = i;
        }

        return maxLen;
    }
};

/*
# imagine replacing each num > 8 by 1 and each num <= 8 by -1
# now the ques reducess to finding the max-len of subarray 
  with sum > 0
*/