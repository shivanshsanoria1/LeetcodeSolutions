class Solution {
public:
    void merge(vector<int>& vec, int left, int mid, int right){
        // left-subarray from [left, mid]
        // right-subarray from [mid+1, right]
        // merged-subarray from [left, right]
        vector<int> merged;
        int i = left; // start index of left-subarray
        int j = mid + 1; // start index of right-subarray
        // both subarrays have elements remaining
        while(i <= mid && j <= right) 
        {
            if(vec[i] <= vec[j])
            {
                merged.push_back(vec[i]);
                i++;
            }
            else
            {
                merged.push_back(vec[j]);
                j++;
            }
        }
        // elements are remaining in left-subarray
        while(i <= mid) 
        {
            merged.push_back(vec[i]);
            i++;
        }
        // elements are remaining in right-subarray
        while(j <= right) 
        {
            merged.push_back(vec[j]);
            j++;
        }
        // copy the elements from temp subarray into the original array
        for(int k=left; k <= right; k++)
            vec[k] = merged[k - left];
    }
    
    void mergeSort(vector<int>& vec, int left, int right){
        if(left >= right)
            return;
        int mid = left + (right - left) / 2;
        mergeSort(vec, left, mid); // left-subarray from [left, mid]
        mergeSort(vec, mid + 1, right); // right-subarray from [mid+1, right]
        merge(vec, left, mid, right); // merged-subarray from [left,right]
    }
    
    vector<int> sortArray(vector<int>& nums) { // Merge-sort, T.C.O(n*logn)
        int n=nums.size();
        mergeSort(nums, 0, n-1);
        return nums;
    }
};