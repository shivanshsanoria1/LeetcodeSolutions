class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n);
        if(n==0) //return empty vector
            return ans;
        vector<vector<int>> vec(n,vector<int> (2)); //2d vector of n rows ans 2 cols (num -> rank)
        for(int i=0; i<n; i++) //fill arr[i] in vec col 0
            vec[i][0]=arr[i];
        sort(vec.begin(),vec.end()); //sort vec by col 0
        int rank=1;
        vec[0][1]=1; //smallest element has rank 1
        for(int i=1; i<n; i++)
        {
            if(vec[i][0] != vec[i-1][0]) //if adjacent elements are not equal increment rank
                rank++;
            vec[i][1]=rank; //fill the rank of each element
        }
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++) //find arr[i] in vec col 0
                if(arr[i]==vec[j][0])
                {
                    ans[i]=vec[j][1]; //add the rank corresponding to arr[i] in ans
                    break;
                }
        return ans;
    }
};