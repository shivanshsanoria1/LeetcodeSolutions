class Solution {
public:
    // T.C.=O(n*logn), S.C.=O(1)
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(), nums.end());

        // num of operations required
        long long int ops = 0;
        // index of median
        int mid = n/2;

        if(nums[mid] < k)
        {
            // nums in the left-half, ie, [0, mid-1]
            // require no modification
            // nums in right-half, ie, [mid, n-1]
            // and smaller than k require modification
            for(int i=mid; i<n && nums[i] < k; i++)
                ops += k - nums[i];
        }
        else if(nums[mid] > k)
        {
            // nums in the right-half, ie, [mid+1, n-1]
            // require no modification
            // nums in left-half, ie, [0, mid]
            // and greater than k require modification
            for(int i=mid; i>=0 && nums[i] > k; i--)
                ops += nums[i] - k;
        }

        return ops;
    }
};