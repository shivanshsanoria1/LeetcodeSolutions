class Solution {
public:
    // T.C.=O(n*log(n) + k*log(n)), S.C.=O(n)
    int minStoneSum(vector<int>& piles, int k) {
        int totalSum = accumulate(piles.begin(), piles.end(), 0);
        // max-heap
        priority_queue<int> pq(piles.begin(), piles.end());

        while(!pq.empty() && k--)
        {
            int curr = pq.top();
            pq.pop();

            totalSum -= curr/2;

            curr -= curr/2;
            if(curr > 0)
                pq.push(curr);
        }

        return totalSum;
    }
};