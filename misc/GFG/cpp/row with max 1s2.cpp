class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int ans=-1;
	    int min_col=m;
	    for(int i=0; i<n; i++)
	    {
	        for(int j=0; j<min_col; j++)
	            if(arr[i][j]==1)
	            {
	                min_col=j;
	                ans=i;
	                break;
	            }
	    }
	    return ans;
	}

};