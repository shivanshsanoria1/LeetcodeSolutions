class Solution {
private:
    #define MOD int(1e9 + 7)

public:
    // T.C.=O(n^2), S.C.=O(1)
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for(int j=1; j<n-1; j++)
        {
            int leftCount = 0;
            for(int i=j-1; i>=0; i--)
                if(nums[i] == 2*nums[j])
                    leftCount++;
            
            int rightCount = 0;
            for(int k=j+1; k<n; k++)
                if(nums[k] == 2*nums[j])
                    rightCount++;
            
            count += ((long long int)leftCount * rightCount) % MOD;
        }

        return count;
    }
};