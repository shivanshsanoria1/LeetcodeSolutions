class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) { //T.C.=O(n) , S.C.=O(1)
        vector<int> ans;
        int smaller=0, equal=0; //count of nums. smaller than target and equal to target
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] < target)
                smaller++;
            else if(nums[i] == target)
                equal++;
        }
        int index=smaller;
        while(equal--)
        {
            ans.push_back(index);
            index++;
        }
        return ans;
    }
};