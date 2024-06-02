class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        int ans = INT_MAX;

        for(int i=0; i<n; i++)
        {
            int a = INT_MAX;

            for(int j=i; j<n; j++)
            {
                a &= nums[j];
                ans = min(ans, abs(a - k));
            }
        }

        return ans;
    }
};
/*
# using the property of bitwise AND: A & 1 = A
# the default value of 'a' is taken as INT_MAX
  because it has all its bits set
# int binary: INT_MAX = (111...111) 31 times
*/