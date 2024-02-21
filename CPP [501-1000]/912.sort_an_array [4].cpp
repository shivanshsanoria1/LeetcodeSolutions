class Solution {
public:
    // returns the digit of num at 'pos' position
    int getDigit(int num, int pos){
        return (num / pos) % 10;
    }

    void radixSort(vector<int>& nums, int pos){
        int n=nums.size();
        vector<int> freq(10, 0); 
        vector<int> sorted(n);
        // freq of digit at 'pos' position for each number
        for(int num: nums)
            freq[getDigit(num, pos)]++;
        // prefix sum of freqs
        for(int i=1; i<10; i++)
            freq[i] += freq[i-1];
        for(int i=n-1; i>=0; i--)
        {
            // index of nums[i] in sorted array
            int idx = --freq[getDigit(nums[i], pos)];
            sorted[idx] = nums[i];
        }
        nums = sorted;
    }

    vector<int> sortArray(vector<int>& nums) { // Radix-sort, T.C.=O(n*d), S.C.=O(n)
        int minVal = *min_element(nums.begin(), nums.end());
        // make all elements in array >= 0
        for(int& num: nums)
            num -= minVal;
        int maxVal = *max_element(nums.begin(), nums.end());
        int pos = 1; // pos=1,10,100,1000,... 
        while(maxVal / pos > 0)
        {
            radixSort(nums, pos);
            pos *= 10;
        }
        // restore all elements of array
        for(int& num: nums)
            num += minVal;
        return nums;
    }
};
// d: max num of digits of any num in nums[] 