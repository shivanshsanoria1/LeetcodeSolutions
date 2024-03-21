class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int evenSum = 0;
        for(int num: nums)
            if(num % 2 == 0)
                evenSum += num;

        vector<int> ans;

        for(vector<int>& query: queries)
        {
            int val = query[0];
            int idx = query[1];

            if(nums[idx] % 2 == 0)
                evenSum -= nums[idx];

            nums[idx] += val;

            if(nums[idx] % 2 == 0)
                evenSum += nums[idx];

            ans.push_back(evenSum);
        }

        return ans;
    }
};