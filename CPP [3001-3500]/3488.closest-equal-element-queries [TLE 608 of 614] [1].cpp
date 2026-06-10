class Solution {
public:
    // T.C.=O(q*n), S.C.=O(1)
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<int> ans;

        for(int i: queries)
        {
            int minDist = n;

            for(int j = (i-1+n) % n; j != i; j = (j-1+n) % n)
                if(nums[i] == nums[j])
                {
                    minDist = min(minDist, abs(i - j));
                    minDist = min(minDist, n - abs(i - j));
                    break;
                }
            
            for(int j = (i+1) % n; j != i; j = (j+1) % n)
                if(nums[i] == nums[j])
                {
                    minDist = min(minDist, abs(i - j));
                    minDist = min(minDist, n - abs(i - j));
                    break;
                }

            ans.push_back(minDist == n ? -1 : minDist);
        }

        return ans;
    }
};