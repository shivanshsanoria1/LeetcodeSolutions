class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    // Greedy
    int minChanges(string s) {
        int ops = 0; // operations
        for(int i=0; i<s.length(); i += 2)
            if(s[i] != s[i+1])
                ops++;
                
        return ops;
    }
};

/*
# we have to partition the string into 'beautiful' partitions
# 'beautiful' partition: must be of even length and made up of only 1's or 0's
# if a partition is 'beautiful' then it must be made of 'beautiful' partitions; 
  in other words; a 'beautiful' partition can be partitioned into 'beautiful'
  partitions recursively until we reach a partition of length 2
# so the problem reduces to counting all the partitions of length 2 that are not 'beautiful'
# 'beautiful' partition of length 2 are "00" and "11"
# 'non-beautiful' partition of length 2 are "01" and "10"
*/