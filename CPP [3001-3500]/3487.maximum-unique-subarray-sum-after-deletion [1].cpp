class Solution {
public:
    // T.C.=O(n + 100), S.C.=O(100)
    int maxSum(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        if(maxNum < 0)
            return maxNum;
        
        vector<bool> isPresent(101, false);

        for(int num: nums)
            if(num > 0)
                isPresent[num] = true;
        
        int sum = 0;
        for(int i=1; i<=100; i++)
            if(isPresent[i])
                sum += i;
        
        return sum;
    }
};