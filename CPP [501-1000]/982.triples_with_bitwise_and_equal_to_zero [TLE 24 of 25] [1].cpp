class Solution {
public:
    // T.C.=O(n^3), S.C.=O(1)
    int countTriplets(vector<int>& nums) {
        int n=nums.size();
        int count = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                for(int k=0; k<n; k++)
                    if((nums[i] & nums[j] & nums[k]) == 0)
                        count++;
        
        return count;
    }
};