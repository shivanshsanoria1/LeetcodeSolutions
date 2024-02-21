class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<int> pq; // max_heap
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                pq.push(matrix[i][j]);
                if(pq.size() > k) // if max_heap size exceeds k then pop the max element from heap
                    pq.pop();
            }
        return pq.top();
    }
};