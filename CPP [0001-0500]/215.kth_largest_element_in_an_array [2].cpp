class Solution {
public:
    // T.C.=O(n*log(k)), S.C.=O(k)
    int findKthLargest(vector<int>& nums, int k) {
        // min-heap
        priority_queue<int, vector<int>, greater<int>> pq; 
        for(int num: nums)
        {
            pq.push(num);
            if(pq.size() == k+1)
                pq.pop();
        }

        return pq.top();
    }
};