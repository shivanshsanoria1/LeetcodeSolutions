class Solution {
public:
    // T.C.=O((n^2)*logn(n^2)), S.C.=O(n^2)
    int medianOfUniquenessArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> uniqueness;

        for(int i=0; i<n; i++)
        {
            unordered_set<int> s;

            for(int j=i; j<n; j++)
            {
                s.insert(nums[j]);
                uniqueness.push_back(s.size());
            }
        }

        sort(uniqueness.begin(), uniqueness.end());

        int n2 = uniqueness.size();
        return n2 % 2 == 0 ? uniqueness[n2/2 - 1] : uniqueness[(n2-1)/2];
    }
};