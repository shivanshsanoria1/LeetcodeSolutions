class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) { // T.C.=O(n*logn + n*q), S.C.=O(1)
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int qu: queries)
        {
            int sum = 0;
            int idx = -1;
            for(int i=0; i<nums.size(); i++)
            {
                if(sum + nums[i] <= qu)
                {
                    sum += nums[i];
                    idx = i;
                }
                else
                    break;
            }
            ans.push_back(idx + 1);
        }
        return ans;
    }
};