class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) { 
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> freqs(maxVal - minVal + 1, 0);
        for(int num: nums)
            freqs[num - minVal]++;
        int k2 = k;
        for(int i=freqs.size()-1; i>=0; i--)
        {
            k2 -= freqs[i];
            if(k2 <= 0)
                return i + minVal;
        }
        return -1;
    }
};
// Counting sort, T.C.=O(n + maxVal - minVal), S.C.=O(maxVal - minVal)