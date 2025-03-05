class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int countPartitions(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum % 2 == 0 ? nums.size()-1 : 0;
    }
};

/*
# suppose the sum of left and right partitions are L and R respectively
# then (L+R) = total sum of the array
# for abs(L-R) to be even, there can be only 2 cases:
  (1) both L and R are even, thus (L+R) will be even
  (2) both L and R are odd, thus (L+R) will be even
# in both the cases, total sum of the array is even and 
  there are exactly n-1 indexes for partitions
# incase the total sum of the array is odd, there will be no indexes for partitions
*/