class Solution {
public:
    // T.C.=O(n*logn), S.C.=O(n)
    int lastStoneWeight(vector<int>& stones) {
        // push all elements in max-heap
        priority_queue<int> pq(stones.begin(), stones.end()); 

        while(pq.size() > 1)
        {
            int max1 = pq.top();
            pq.pop();
            int max2 = pq.top();
            pq.pop();

            if(max1 - max2 > 0)
                pq.push(max1 - max2);
        }

        return !pq.empty() ? pq.top() : 0;
    }
};