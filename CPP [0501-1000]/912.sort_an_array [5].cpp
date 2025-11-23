class Solution {
public:
    // T.C.=O(n + r), S.C.=O(r)
    // r: (maxVal - minVal)
    // Counting-sort with vector
    vector<int> sortArray(vector<int>& nums) {
        int minVal = *min_element(nums.begin(), nums.end());

        // make all elements in array >= 0
        for(int& num: nums)
            num -= minVal;

        int maxVal = *max_element(nums.begin(), nums.end());
        
        vector<int> freq(maxVal + 1, 0);
        for(int num: nums)
            freq[num]++;

        for(int num = 0, i = 0; num < freq.size(); num++)
        {
            int f = freq[num];
            while(f--)
            {
                nums[i] = num;
                i++;
            }
        }

        // restore all elements of array
        for(int& num: nums)
            num += minVal;

        return nums;
    }
};