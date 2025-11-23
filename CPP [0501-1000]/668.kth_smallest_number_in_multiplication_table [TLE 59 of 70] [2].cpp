class Solution {
public:
    int findKthNumber(int m, int n, int k) { // T.C.=O(m*n*logk), S.C.=O(k)
        priority_queue<int> pq; // max-heap
        for(int i=1; i<=m; i++)
            for(int j=1; j<=n; j++)
            {
                pq.push(i*j);
                // heap can have at max k elements
                if(pq.size() == k + 1) 
                    pq.pop();
            }
        return pq.top();
    }
};