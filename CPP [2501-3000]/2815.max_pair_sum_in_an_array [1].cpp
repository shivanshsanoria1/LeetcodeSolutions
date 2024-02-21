class Solution {
public:
    int maxDigit(int num){
        int maxDig = 0;
        while(num > 0)
        {
            int dig = num % 10;
            num /= 10;
            maxDig = max(maxDig, dig);
        }
        return maxDig;
    }

    int maxSum(vector<int>& nums) { // T.C.=O(n^2), S.C.=O(1)
        int n=nums.size();
        int ans = -1;
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                if(maxDigit(nums[i]) == maxDigit(nums[j]))
                    ans = max(ans, nums[i] + nums[j]);
        return ans;
    }
};
