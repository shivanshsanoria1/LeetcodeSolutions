class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(1)
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());

        vector<int> ans;
        for(int num: nums)
            if(ans.empty() || ans.back() != num){
                ans.push_back(num);
                if(--k == 0)
                    break;
            }

        return ans;
    }
};