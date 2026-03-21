class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) { // T.C.=O(n^2)
        int min=INT_MAX, n=nums.size(), curr_sum, ans;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n; i++)
        {
            int j=i+1, k=n-1;
            while(j<k)
            {
                curr_sum=nums[i]+nums[j]+nums[k];
                if(abs(curr_sum-target) < min)
                {
                    min=abs(curr_sum-target);
                    ans=curr_sum;
                }
                if(curr_sum > target)
                    k--;
                else if(curr_sum < target)
                    j++;
                else
                    return curr_sum;
            }
        }
        return ans;
    }
};