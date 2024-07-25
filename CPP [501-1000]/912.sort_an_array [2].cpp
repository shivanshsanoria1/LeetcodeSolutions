class Solution {
private:
    // we can only access the part of nums[] in index range [0, n-1]
    void heapify(vector<int>& nums, int n, int i){
        while(true)
        {
            int maxValIdx = i;

            int left = 2*i + 1; // left-child index
            int right = 2*i + 2; // right-child index

            // left child exists and has val > curr max val
            if(left < n && nums[left] > nums[maxValIdx])
                maxValIdx = left;
            // right child exists and has val > curr max val
            if(right < n && nums[right] > nums[maxValIdx])
                maxValIdx = right;
            
            // i is already the 'maxValIdx'
            if(maxValIdx == i)
                break;
            
            swap(nums[i], nums[maxValIdx]);
            i = maxValIdx;
        }
    }

    void heapSort(vector<int>& nums){
        int n=nums.size();

        // skip the leaf nodes, ie, elements in range [n/2, n-1]
        // build the max-heap through heapify() by iterating in reverse
        for(int i=n/2-1; i>=0; i--) 
            heapify(nums, n, i); 

        // at each step, elemnts in range [i, n-1] will be sorted,
        // so upper limit in heapify() is set as i instead of n
        // at last, element at index 0 will automatically sorted 
        // so no need to run the loop for i=0

        // delete from max-heap
        for(int i=n-1; i>0; i--) 
        {
            // swap the root and last unsorted node
            swap(nums[0], nums[i]);
            // heapify at index 0 
            heapify(nums, i, 0); 
        }
    }

public:
    // T.C.O(n*log(n)), S.C.=O(1)
    // Heap-sort
    vector<int> sortArray(vector<int>& nums) { 
        heapSort(nums);
        return nums;
    }
};
// heapify() is done in Top-Down manner