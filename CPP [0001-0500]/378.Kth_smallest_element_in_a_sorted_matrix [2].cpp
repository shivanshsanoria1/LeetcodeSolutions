class Solution {
public:
    // T.C.=O((n^2)*log(k)), S.C.=O(k)
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        priority_queue<int> pq; // max-heap

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                pq.push(matrix[i][j]);

                if(pq.size() == k+1)
                    pq.pop();
            }

        return pq.top();
    }
};