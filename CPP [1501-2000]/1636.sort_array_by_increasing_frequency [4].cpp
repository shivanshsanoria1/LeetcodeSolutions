class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(201)
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> freq(201, 0);
        for(int num: nums)
            freq[num + 100]++;
        
        sort(nums.begin(), nums.end(), [&](int a, int b){
            return freq[a + 100] == freq[b + 100] ? a > b : freq[a + 100] < freq[b + 100];
        });

        return nums;
    }
};
/*
# each num in nums[] is in range [-100, 100]
# adding 100 to each num changes the range to [0, 200]
# so an array of size 201 is required for Counting-sort
*/