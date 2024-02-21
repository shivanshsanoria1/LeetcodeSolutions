class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) { // T.C.=O(n), S.C.=O(101)
        vector<int> freq(101, 0);
        int totalSum = 0;
        for(int num: nums)
        {
            freq[num]++;
            totalSum += num;
        }
        vector<int> ans;
        int sum = 0;
        for(int i=100; i>=1; i--)
            while(freq[i] > 0 && sum <= totalSum/2)
            {
                ans.push_back(i);
                sum += i;
                freq[i]--;
            }
        return ans;
    }
};