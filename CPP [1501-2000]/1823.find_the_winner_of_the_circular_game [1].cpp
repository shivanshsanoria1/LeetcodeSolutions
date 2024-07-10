class Solution {
public:
    // T.C.=O(n*k), S.C.=O(n)
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1; i<=n; i++)
            q.push(i);
        
        while(q.size() > 1)
        {
            // pop (k-1) elements from front 
            // and push them in the rear
            int i = k-1;
            while(i--)
            {
                q.push(q.front());
                q.pop();
            }
            // pop the kth element
            q.pop();
        }

        return q.front();
    }
};