class Solution {
public:
    // T.C.=O(n^4), S.C.=O(1)
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        long long int count = 0;

        for(int i=0; i<n-3; i++)
            for(int j=i+1; j<n-2; j++)
            {
                if(nums[i] > nums[j])
                    continue;
                for(int k=j+1; k<n-1; k++)
                {
                    if(nums[i] > nums[k] || nums[j] < nums[k])
                        continue;
                    for(int l=k+1; l<n; l++)
                        if(nums[j] < nums[l])
                            count++;
                }
            }

        return count;
    }
};

// i < j < k < l
// nums[i] < nums[k] < nums[j] < nums[l]