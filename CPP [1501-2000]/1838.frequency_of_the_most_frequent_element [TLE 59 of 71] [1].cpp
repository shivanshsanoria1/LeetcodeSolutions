class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) { // T.C.=O(n^2), S.C.=O(1)
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int maxFreq = 1;
        for(int i=n-1; i>=0; i--)
        {
            int freq = 1;
            int tempK = k;
            for(int j=i-1; j>=0; j--)
            {
                int diff = nums[i] - nums[j];
                if(diff > tempK)
                    break;
                freq++;
                tempK -= diff;
            }
            maxFreq = max(maxFreq, freq);
        }
        return maxFreq;
    }
};