class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) { // T.C.=O((n+k)*logn), S.C.=O(n)
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end()); // min-heap
        while(k--)
        {
            int curr = pq.top();
            pq.pop();
            if(curr == 0) // no more -ive left in min-heap
                break;
            pq.push(-1*curr); // push the -ive of curr element into min-heap
        }
        int sum = 0;
        while(!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};