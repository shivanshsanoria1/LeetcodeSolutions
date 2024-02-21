class Solution {
public:
    int specialArray(vector<int>& nums) { // T.C.=O(n^2), S.C.=O(1)
        int n=nums.size();
        for(int x=1; x<=n; x++)
        {
            int count = 0;
            for(int i=0; i<n; i++)
            {
                if(nums[i] >= x)
                    count++;
                if(count > x)
                    break;
            }
            if(count == x)
                return x;
        }
        return -1;
    }
};