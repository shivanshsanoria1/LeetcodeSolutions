class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int ans=-1;
	    int max_sum=0;
	    for(int i=0; i<n; i++)
	    {
	        int sum=0;
	        for(int j=0; j<m; j++)
	            sum += arr[i][j];
	        if(sum > max_sum)
	        {
	            max_sum=sum;
	            ans=i;
	        }
	    }
	    return ans;
	    
	}

};