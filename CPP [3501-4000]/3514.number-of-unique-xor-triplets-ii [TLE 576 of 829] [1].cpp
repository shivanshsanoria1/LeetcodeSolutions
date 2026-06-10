class Solution {
public:
    // T.C.=O(n^3), S.C.=O(m2)
    // m2: a num made up of b set bits
    // b: min num of bits required to represent the max num in nums[]
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;

        for(int i=0; i<n; i++)
            for(int j=i; j<n; j++)
                for(int k=j; k<n; k++)
                    s.insert(nums[i] ^ nums[j] ^ nums[k]);

        return s.size();
    }
};