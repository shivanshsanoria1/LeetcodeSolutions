class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long int> ans;
        int maxVal = 0;
        long long int score = 0;
        for(int num: nums)
        {
            maxVal = max(num, maxVal);
            ans.push_back(num + maxVal + score);
            score += num + maxVal;
        }
        return ans;
    }
};