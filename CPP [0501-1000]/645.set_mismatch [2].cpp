class Solution {
public:
    // T.C.=O(n), S.C.=O(n)
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2);
        int n=nums.size();
        vector<bool> visited(n+1, false);
        int sum = 0;
        int correctSum = (n*(n+1))/2;
        for(int num: nums)
        {
            if(!visited[num])
                visited[num] = true;
            else // duplicate found
                ans[0] = num;
            sum += num;
        }
        ans[1] = correctSum - sum + ans[0];
        return ans;
    }
};