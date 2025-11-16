class Solution {
public:
    // T.C.=O(n + 100), S.C.=O(100)
    vector<int> findMissingElements(vector<int>& nums) {
        int minNum = *min_element(nums.begin(), nums.end());
        int maxNum = *max_element(nums.begin(), nums.end());

        vector<int> isPresent(101, false);
        for(int num: nums)
            isPresent[num] = true;
        
        vector<int> missingNums;
        for(int i=minNum; i<=maxNum; i++)
            if(!isPresent[i])
                missingNums.push_back(i);
        
        return missingNums;
    }
};