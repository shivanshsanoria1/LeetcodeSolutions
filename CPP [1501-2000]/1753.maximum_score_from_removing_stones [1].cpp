class Solution {
public:
    // T.C.=O(a + b + c), S.C.=O(1)
    // Greedy
    int maximumScore(int a, int b, int c) {
        priority_queue<int> pq; // max-heap
        pq.push(a);
        pq.push(b);
        pq.push(c);

        int count = 0;

        while(pq.size() >= 2)
        {
            int max1 = pq.top();
            pq.pop();
            int max2 = pq.top();
            pq.pop();

            count++;

            if(--max1 > 0)
                pq.push(max1);
            if(--max2 > 0)
                pq.push(max2);
        }

        return count;
    }
};