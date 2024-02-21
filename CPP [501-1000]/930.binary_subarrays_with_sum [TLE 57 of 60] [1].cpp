class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) { // T.C.=O(n^2), S.C.=O(1)
        int n=nums.size();
        int count = 0;
        for(int i=0; i<n; i++)
        {
            int sum = 0;
            for(int j=i; j<n; j++)
            {
                sum += nums[j];
                if(sum == goal)
                    count++;
                else if(sum > goal)
                    break;
            }
        }
        return count;
    }
};