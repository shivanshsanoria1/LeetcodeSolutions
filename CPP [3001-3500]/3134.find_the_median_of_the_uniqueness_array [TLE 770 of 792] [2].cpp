class Solution {
public:
    // T.C.=O(n^2), S.C.=O(n)
    int medianOfUniquenessArray(vector<int>& nums) {
        int n=nums.size();
        // unique[i]: num of subarrays with 
        // 'i' unique unique elements
        vector<int> unique(n+1, 0);

        for(int i=0; i<n; i++)
        {
            unordered_set<int> s;

            for(int j=i; j<n; j++)
            {
                s.insert(nums[j]);
                unique[s.size()]++;
            }
        }

        int n2 = n*(n+1)/2;
        // position of median (0-based)
        int pos = n2 % 2 == 0 ? n2/2 - 1 : (n2-1)/2;

        int i = 1;

        for(; i<=n && unique[i] <= pos; i++)
            pos -= unique[i];

        return i;
    }
};