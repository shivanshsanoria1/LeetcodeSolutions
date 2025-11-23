class Solution {
private:
    void merge(vector<int>& nums, int left, int mid, int right){
        // left-subarray from [left, mid]
        // right-subarray from [mid + 1, right]
        // merged-subarray from [left, right]
        vector<int> merged;

        int i = left; // start index of left-subarray
        int j = mid + 1; // start index of right-subarray

        // both subarrays have elements remaining
        while(i <= mid && j <= right) 
        {
            if(nums[i] <= nums[j])
            {
                merged.push_back(nums[i]);
                i++;
            }
            else
            {
                merged.push_back(nums[j]);
                j++;
            }
        }

        // elements are remaining in left-subarray
        while(i <= mid) 
        {
            merged.push_back(nums[i]);
            i++;
        }

        // elements are remaining in right-subarray
        while(j <= right) 
        {
            merged.push_back(nums[j]);
            j++;
        }

        // copy the elements from temp subarray into the original array
        for(int k=left; k <= right; k++)
            nums[k] = merged[k - left];
    }
    
    void mergeSort(vector<int>& nums, int left, int right){
        if(left >= right)
            return;

        int mid = left + (right - left) / 2;

        // left-subarray from [left, mid]
        mergeSort(nums, left, mid); 
        // right-subarray from [mid + 1, right]
        mergeSort(nums, mid + 1, right); 

        // merged-subarray from [left, right]
        merge(nums, left, mid, right); 
    }

public:
    // T.C.O(n*log(n)), S.C.=O(n)
    // Merge-sort
    vector<int> sortArray(vector<int>& nums) { 
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};