class Solution {
public:
    // T.C.=O(n^2), S.C.=O(1)
    int countPairs(vector<int>& nums, int low, int high) {
        int n=nums.size();
        int count = 0;

        for(int i=0; i<n; i++)
            for(int j=i; j<n; j++)
            {
                int x = nums[i] ^ nums[j];
                if(x >= low && x <= high)
                    count++;
            }
        
        return count;
    }
};