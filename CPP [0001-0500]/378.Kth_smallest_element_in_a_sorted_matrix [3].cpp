class Solution {
private:
    int countElementsLessThanOrEqualToKey(vector<vector<int>>& matrix, int key){
        int n=matrix.size();
        int count = 0;
        // perform Binary-Search on each row whose min val <= key
        for(int i=0; i<n && matrix[i][0] <= key; i++)
        {
            int left = 0, right = n-1;
            int colIdx = 0;

            while(left <= right)
            {
                int mid = left + (right - left)/2;

                if(matrix[i][mid] > key)
                    right = mid - 1;
                else
                {
                    colIdx = mid;
                    left = mid + 1;
                }
            }

            count += colIdx + 1;
        }

        return count;
    }

public:
    // T.C.=O(log(max - min) * n*logn), S.C.=O(1)
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        // min val at (0, 0) and max val at (n-1, n-1)
        int left = matrix[0][0], right = matrix[n-1][n-1];

        while(left <= right)
        {
            int mid = left + (right - left)/2;

            if(countElementsLessThanOrEqualToKey(matrix, mid) < k)
                left = mid + 1;
            else
                right = mid - 1;    
        }

        return left;
    }
};