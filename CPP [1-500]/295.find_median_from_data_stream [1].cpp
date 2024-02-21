class MedianFinder {
private:
    // for the elemnts in the 1st half of sorted array
    priority_queue<int> maxHeap; 
    // for the elemnts in the 2nd half of sorted array
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        // insert in max-heap by default
        maxHeap.push(num);

        int maxHeapSize = maxHeap.size();
        int minHeapSize = minHeap.size();
        
        // pop from max-heap and push in min-heap
        if(maxHeapSize - minHeapSize > 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        // pop from min-heap and push in max-heap
        else if(minHeapSize - maxHeapSize > 1)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        // swap the tops from both heaps
        if(!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top())
        {
            int curr1 = maxHeap.top();
            int curr2 = minHeap.top();
            maxHeap.pop();
            minHeap.pop();
            minHeap.push(curr1);
            maxHeap.push(curr2);
        }
    }
    
    double findMedian() {
        if(maxHeap.size() - minHeap.size() == 1)
            return maxHeap.top();
        else if(minHeap.size() - maxHeap.size() == 1)
            return minHeap.top();
        // maxHeap.size() == minHeap.size()
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

/*
# max-heap is used to store the 1st half of sorted array
# min-heap is used to store the 2nd half of sorted array
# at any point the diff in size of both heaps is 0 or 1
# if the diff in size of heaps is 1 then there are odd num of elements in sorted array,
so median is the top of the larger size heap
# if the diff in size of heaps is 0 then there are even num of elements in sorted array,
so median is the avg. value of top of both heaps
*/

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */