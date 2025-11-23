class Solution {
private:
    // returns the digit of num at 'pos' position
    int getDigit(int num, int pos){
        return (num / pos) % 10;
    }

    void radixSort(vector<int>& nums, int pos){
        vector<int> freq(10, 0); 
        // freq of digit at 'pos' position for each number
        for(int num: nums)
            freq[getDigit(num, pos)]++;
        
        // prefix sum of freqs
        for(int i=1; i<10; i++)
            freq[i] += freq[i-1];

        int n=nums.size();
        vector<int> temp(n);
        for(int i=n-1; i>=0; i--)
        {
            // index of nums[i] in sorted array
            int idx = --freq[getDigit(nums[i], pos)];
            temp[idx] = nums[i];
        }

        nums = temp;
    }

public:
    // T.C.=O((n + 10) * d), S.C.=O(n)
    // d: max num of digits of any num in nums[] 
    // Radix-sort
    vector<int> sortArray(vector<int>& nums) { 
        int minVal = *min_element(nums.begin(), nums.end());

        // make all elements in array >= 0
        for(int& num: nums)
            num -= minVal;

        int maxVal = *max_element(nums.begin(), nums.end());

        for(int pos = 1; maxVal/pos > 0; pos *= 10)
            radixSort(nums, pos);

        // restore all elements of array
        for(int& num: nums)
            num += minVal;

        return nums;
    }
};
// pos = 1, 10, 100, 1000, ... 