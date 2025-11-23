class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) { // T.C.=O(n^2) , S.C.=O(1)
        int n=nums.size();
        for(int i=0; i<n; i++)
        {
            if(i%2==0 && nums[i]%2!=0) // index is even , num. is odd
            {
                for(int j=i+1; j<n; j++) // search for next even num.
                {
                    if(nums[j]%2==0)
                    {
                        swap(nums[i],nums[j]);
                        break;
                    }
                }
            }
            else if(i%2!=0 && nums[i]%2==0) // index is odd , num. is even
            {
                for(int j=i+1; j<n; j++) // search for next odd num.
                {
                    if(nums[j]%2!=0)
                    {
                        swap(nums[i],nums[j]);
                        break;
                    }
                }
            }
        }
        return nums;
    }
};