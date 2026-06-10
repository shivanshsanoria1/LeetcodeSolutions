class Solution {
public:
    // T.C.=O(n), S.C.=O(100)
    int minimumOperations(vector<int>& nums) {
        vector<bool> isFound(101, false);
        for(int i=nums.size()-1; i>=0; i--)
        {
            if(isFound[nums[i]])
                return (i+1)/3 + ((i+1) % 3 == 0 ? 0 : 1);

            isFound[nums[i]] = true;
        }

        return 0;
    }
};