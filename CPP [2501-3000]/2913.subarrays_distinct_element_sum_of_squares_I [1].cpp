class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            vector<int> freq(101, 0);
            int distinctCount = 0;
            for(int j=i; j<n; j++)
            {
                freq[nums[j]]++;
                if(freq[nums[j]] <= 1)
                    distinctCount++;
                sum += distinctCount * distinctCount;
            }
        }
        return sum;
    }
};