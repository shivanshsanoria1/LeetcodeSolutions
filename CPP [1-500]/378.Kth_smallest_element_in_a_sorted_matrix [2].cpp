class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int low=matrix[0][0], high=matrix[n-1][n-1], mid;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(count_elements_lessthanorequalto_mid(matrix,n,mid) >= k)
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
    
    int count_elements_lessthanorequalto_mid(vector<vector<int>>& matrix, int n, int mid)
    {
        int c=0;
        for(int i=0; i<n; i++)
        {
            for(int j=n-1; j>=0; j--)
            {
                if(matrix[i][j]<=mid) // if an element is <= mid then all elements to its left
                {                     // will also be <= mid
                    c = c + j+1;
                    break;
                }
            }
        }
        return c;
    }
};

