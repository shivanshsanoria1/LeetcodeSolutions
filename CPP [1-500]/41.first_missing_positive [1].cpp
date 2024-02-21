class Solution {
public:
    int firstMissingPositive(vector<int>& nums) { // T.C.=O(nlogn) ; S.C.=O(1)
        int n=nums.size(), min=1;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n; i++)
        {
            if(nums[i]>0)
            {
                if(nums[i]==min)
                    min++;
                else if(nums[i]>min)
                    return min;
            }
        }
        return min;
    }
};