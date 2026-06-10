class Solution {
public:
    int countSetBits(int n)
    {
        int c=0;
        while(n)
        {
            if(n%2==1)
                c++;
            n=n/2;
        }
        return c;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> pairs(n,vector<int> (2)); // 2d vector with n rows and 2 cols., col.0 for set bits count, col.1 for element
        vector<int> ans(n);
        for(int i=0; i<n; i++)
        {
            pairs[i][0]=countSetBits(arr[i]);
            pairs[i][1]=arr[i];
        }
        sort(pairs.begin(),pairs.end());
        for(int i=0; i<n; i++)
            ans[i]=pairs[i][1];
        return ans;
    }
};