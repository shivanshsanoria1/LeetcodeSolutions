class Solution {
public:
    // T.C.=O(n), S.C.=O(m)
    // m: max num in nums[], which is 1000 here
    // Counting-sort
    int specialArray(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<int> freq(maxNum + 1, 0);
        for(int num: nums)
            freq[num]++;
        
        int postfixSum = 0;
        for(int i=freq.size()-1; i>=0; i--)
        {
            postfixSum += freq[i];
            if(postfixSum == i)
                return i;
        }

        return -1;
    }
};