class Solution {
public:
    int countQuadruplets(vector<int>& nums) { // T.C.=O(n^4), S.C.=O(1)
        int n=nums.size();
        int count = 0;
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
                for(int k=j+1; k<n; k++)
                    for(int l=k+1; l<n; l++)
                        if(nums[i] + nums[j] + nums[k] == nums[l])
                            count++;
        return count;
    }
};