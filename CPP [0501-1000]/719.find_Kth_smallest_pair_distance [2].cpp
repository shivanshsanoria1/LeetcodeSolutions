class Solution {
private:
    // returns num of pairs with abs diff <= d
    int pairsWithAbsDiffLessThanEqual_d(vector<int>& nums, int d){
        int left = 0, right = 0;
        int count = 0;

        while(right < nums.size())
        {
            // shrink the window until the diff 
            // between max and min vals become <= d
            while(nums[right] - nums[left] > d)
                left++;

            // element at 'right' can be paired with 
            // any element in index range [left, right-1],
            // ie, (right-1 - left + 1) = (right - left) elements
            count += right - left;

            right++;
        }

        return count;
    }

public:
    // T.C.=O(n*log(n) + n*log(m)), S.C.=O(1)
    // m: max val in nums[]
    // Sorting + Binary-search + Sliding-window
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int minVal = *min_element(nums.begin(), nums.end()); 
        int maxVal = *max_element(nums.begin(), nums.end()); 

        int left = 0, right = maxVal - minVal;
        int diff = -1;
        while(left <= right)
        {
            int mid = left + (right - left)/2;

            if(pairsWithAbsDiffLessThanEqual_d(nums, mid) >= k)
            {
                diff = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }

        return diff;
    }
};
/*
# min possible abs diff is 0, 
  when both max and min vals are the same
# otherwise the max possbile abs diff is (maxVal - minVal)
# so the abs diff varies in range [0, maxVal - minVal]
# the problem now reduces to finding 
  the smallest possible abs diff, say 'd'
  such that there are >= k pairs with abs diff <= d
*/