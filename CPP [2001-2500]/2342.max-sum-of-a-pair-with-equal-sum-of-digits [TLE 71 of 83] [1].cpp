class Solution {
public:
    int digitSum(int num)
    {
        int sum = 0;
        while(num > 0)
        {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) { // T.C.=O(n^2), S.C.=O(n)
        int n = nums.size();
        vector<pair<int, int>> vec; // {num, digitSum}
        for(int i=0; i<n; i++)
            vec.push_back({nums[i], digitSum(nums[i])});
        int ans = -1;
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                if(vec[i].second == vec[j].second)
                    ans = max(ans, nums[i] + nums[j]);
        return ans;
    }
};