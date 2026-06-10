class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int count = 0;

        for(int i=0; i<=n-3; i++)
            for(int j=i+1; j<=n-2; j++)
            {
                if(2*nums[j] == nums[j-1] + nums[j+1])
                    count++;
                else
                    break;
            }

        return count;
    }
};