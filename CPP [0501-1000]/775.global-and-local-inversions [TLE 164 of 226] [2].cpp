class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) { //T.C.=O(n^2) , S.C.=O(1)
        int n=nums.size();
        int loc_inv=0, glo_inv=0;
        for(int i=0; i<n-1; i++)
        {
            if(nums[i] > nums[i+1]) //count local inversions
                loc_inv++;
            for(int j=i+1; j<n; j++) //count global inversions
                if(nums[i] > nums[j])
                    glo_inv++;
        }
        return glo_inv==loc_inv ? true : false;
    }
};