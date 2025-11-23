class Solution {
public:
    // T.C.=O(n + (maxVal - minVal)), S.C.=O(maxVal - minVal)
    // Counting-sort
    int findKthLargest(vector<int>& nums, int k) { 
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());

        vector<int> freq(maxVal - minVal + 1, 0);
        for(int num: nums)
            freq[num - minVal]++;

        for(int i=freq.size()-1; i>=0; i--)
        {
            k -= min(k, freq[i]);
            if(k == 0)
                return i + minVal;
        }

        return -1;
    }
};