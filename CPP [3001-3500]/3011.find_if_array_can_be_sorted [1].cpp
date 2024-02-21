class Solution {
private:
    int setBitCount(int n){
        int count = 0;
        while(n > 0)
        {
            count += n & 1;
            n = n >> 1;
        }
        return count;
    }

public:
    // T.C.=O(8*n^2), S.C.=O(1), similar to bubble-sort
    bool canSortArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=0; i<n-1; i++)
        {
            bool swapped = false;
            for(int j=0; j<n-1-i; j++)
                if(setBitCount(nums[j]) == setBitCount(nums[j+1]) && nums[j] > nums[j+1])
                {
                    swap(nums[j], nums[j+1]);
                    swapped = true;
                }
            if(!swapped)
                break;
        }

        for(int i=1; i<n; i++)
            if(nums[i-1] > nums[i])
                return false;
        return true;
    }
};