class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) { // T.C.=O(n*logk), S.C.=O(k)
        priority_queue<int, vector<int>, greater<int>> pq; // min heap
        for(int num: nums)
        {
            pq.push(num);
            if(pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};