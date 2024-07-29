class Solution {
public:
    // T.C.=O(??), S.C.=O(n)
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        multiset<int> s;
        vector<int> ans(n);

        for(int i=n-1; i>=0; i--)
        {
            s.insert(nums[i]);
            ans[i] = distance(s.begin(), s.lower_bound(nums[i]));
        }

        return ans;
    }
};