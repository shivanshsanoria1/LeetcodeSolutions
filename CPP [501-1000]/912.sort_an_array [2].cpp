class Solution {
public:
    void heapify(vector<int>& vec, int n, int i){
        // i: curr node index
        int largest = i; // index of largest value from vec[i], vec[left], vec[right]
        int left = 2*i + 1; // left-child index
        int right = 2*i + 2; // right-child index
        // left child exists and has value > curr node value
        if(left < n && vec[left] > vec[largest])
            largest = left;
        // right child exists and has value > max(curr node value, left child value)
        if(right < n && vec[right] > vec[largest])
            largest = right;
        if(largest != i) // new largest found
        {
            swap(vec[largest], vec[i]);
            heapify(vec, n, largest);
        }
    }

    void heapSort(vector<int>& vec){
        int n=vec.size();
        // skip the leaf nodes, ie, elements in range [n/2, n-1]
        for(int i=n/2-1; i>=0; i--) // build max-heap
            heapify(vec, n, i); // heapify() at index i
        // at each step elemnts in range [i, n-1] will be sorted,
        // so upper limit in heapify() is set as i instead of n
        // at last element at index 0 will automatically sorted 
        // so no need to run the loop for i=0
        for(int i=n-1; i>0; i--) // delete from max-heap
        {
            swap(vec[0], vec[i]); // swap the root node and the last node
            heapify(vec, i, 0); // heapify() at index 0
        }
    }

    vector<int> sortArray(vector<int>& nums) { // Heap-sort, T.C.O(n*logn)
        heapSort(nums);
        return nums;
    }
};