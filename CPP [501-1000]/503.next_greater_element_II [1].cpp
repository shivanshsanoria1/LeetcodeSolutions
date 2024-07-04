class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    vector<int> nextGreaterElements(vector<int>& nums) { 
        int n=nums.size();
        vector<int> nge(n, -1);

        for(int i=0; i<n; i++)
            for(int j = (i+1) % n; j != i; j = (j+1) % n)
                if(nums[j] > nums[i])
                {
                    nge[i] = nums[j];
                    break;
                }

        return nge;
    }
};