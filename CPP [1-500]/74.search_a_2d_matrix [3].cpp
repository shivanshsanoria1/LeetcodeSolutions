class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) { //T.C.=O(log(m*n))
        int m = matrix.size(), n = matrix[0].size();
        // target is smaller than the smallest element or larger than the largest element in the matrix
        if(target < matrix[0][0] || target > matrix[m-1][n-1]) 
            return false;
        int left = 0, right = m*n - 1;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(matrix[mid/n][mid % n] == target)
                return true;
            else if(matrix[mid/n][mid % n] < target) // move to the right subarray
                left = mid + 1;
            else // move to the left subarray
                right = mid - 1;
        }
        return false;
    }
};