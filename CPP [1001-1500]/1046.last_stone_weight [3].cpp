class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        if(n==1) //cannot break only 1 stone
            return stones[0];
        int max1, max2; //largest and 2nd largest num in array in each step
        priority_queue<int> max_heap; //priority queue is same as max heap
        for(int i=0; i<n; i++) //push all elements of array into max heap
            max_heap.push(stones[i]);
        while(max_heap.size() > 1)
        {
            max1=max_heap.top();
            max_heap.pop();
            max2=max_heap.top();
            max_heap.pop();
            if(max1-max2 != 0)
                max_heap.push(max1-max2);
        }
        return !max_heap.empty() ? max_heap.top() : 0; //for non-empty heap return heap.top(), for empty heap return 0
    }
};