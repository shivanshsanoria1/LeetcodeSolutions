class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> vec(n);
        int ans=start; //ans=vec[0]=start+2*0=start
        for(int i=0; i<n; i++)
        {
            vec[i]=start+2*i;
            if(i>=1)
                ans=ans^vec[i];
        }
        return ans;
    }
};