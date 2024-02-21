class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101, 0);
        for(int num: nums)
            freq[num]++;
            
        int maxFreq = 0;
        int count = 0;
        for(int i=1; i<=100; i++)
        {
            // new max freq found
            if(freq[i] > maxFreq)
            {
                maxFreq = freq[i];
                count = freq[i];
            }
            // another max freq found
            else if(freq[i] == maxFreq)
                count += freq[i];
        }
        return count;
    }
};