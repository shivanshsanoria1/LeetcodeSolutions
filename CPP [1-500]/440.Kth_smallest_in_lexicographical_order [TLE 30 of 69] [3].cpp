class Solution {
public:
    // T.C.=O(n*log(k)), S.C.=O(k)
    int findKthNumber(int n, int k) {
        priority_queue<string> pq; // max-heap

        for(int i=1; i<=n; i++)
        {
            pq.push(to_string(i));
            
            if(pq.size() == k+1)
                pq.pop();
        }

        return stoi(pq.top());
    }
};