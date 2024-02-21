class Solution {
public:
    int specialArray(vector<int>& nums) { // T.C.=O(n*logn), S.C.=O(1)
        sort(nums.begin(), nums.end());
        int n=nums.size();
        for(int x=1; x<=n; x++)
        {
            int left = 0, right = n-1;
            int idx = -1;
            while(left <= right)
            {
                int mid = left + (right - left)/2;
                if(nums[mid] >= x)
                {
                    idx = mid;
                    if(right - idx + 1 > x)
                        break;
                    right = mid - 1;
                }
                else // nums[mid] < x
                    left = mid + 1;
            }
            if(n - idx == x)
                return x;
        }
        return -1;
    }
};