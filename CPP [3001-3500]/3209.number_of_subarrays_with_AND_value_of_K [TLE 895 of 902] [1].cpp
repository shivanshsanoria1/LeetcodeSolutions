class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        long long int count = 0;

        for(int i=0; i<n; i++)
        {
            int bitAND = INT_MAX;

            for(int j=i; j<n; j++)
            {
                bitAND &= nums[j];

                if(bitAND == k)
                    count++;
            }
        }

        return count;
    }
};
/*
# using the property of bitwise AND: A & 1 = A
# the default value of 'bitAND' is taken as INT_MAX
  since it has all of its bits set
*/