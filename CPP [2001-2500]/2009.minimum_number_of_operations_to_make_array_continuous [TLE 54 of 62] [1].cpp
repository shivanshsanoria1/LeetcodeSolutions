class Solution {
public:
    int minOperations(vector<int>& nums) { // T.C.=O(n^2), S.C.=O(n)
        unordered_set<int> s(nums.begin(), nums.end());
        int n=nums.size();
        int ans = n-1;
        for(int num: nums)
        {
            int op = 0; // operations required
            for(int d=1; d<n; d++)
                if(s.find(num + d) == s.end()) // not found in set
                    op++;
            ans = min(ans, op);
        }
        return ans;
    }
};
/*
# assume each 'num' in 'nums' to be the min. number and find if 
  num + 1, num + 2, num + 3, ..., num + (n-1) are present in the array
  if any one them is not found then increment the number of operations required
*/