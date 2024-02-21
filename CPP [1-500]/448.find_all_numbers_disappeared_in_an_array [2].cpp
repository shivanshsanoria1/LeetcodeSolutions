class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) { //T.C.=O(n) , S.C.=O(1)
        vector<int> ans;
        int n=nums.size(), index;
        for(int i=0; i<n; i++)
        {
            index=abs(nums[i])-1; //use 'nums[i]-1' as index to the next element
            if(nums[index] > 0) //+ive means not visited
                nums[index] *= -1; //-ive means visited
        }
        for(int i=0; i<n; i++)
            if(nums[i] > 0)
                ans.push_back(i+1);
        return ans;
    }
};