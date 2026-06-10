class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) { // T.C.=O(n^2) , S.C.=O(1)
        vector<int> result;
        int n=nums.size();
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(nums.at(i) + nums.at(j) == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
                    
            }
        }
        return result;
    }
};