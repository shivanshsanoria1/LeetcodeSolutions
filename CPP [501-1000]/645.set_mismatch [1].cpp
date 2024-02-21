class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2);
        int n=nums.size();
        vector<int> freq(n+1, 0);
        int sum = 0;
        int correctSum = (n*(n+1))/2;
        for(int num: nums)
        {
            freq[num]++;
            sum += num;
            if(freq[num] == 2) // duplicate found
                ans[0] = num;
        }
        ans[1] = correctSum - sum + ans[0];
        return ans;
    }
};