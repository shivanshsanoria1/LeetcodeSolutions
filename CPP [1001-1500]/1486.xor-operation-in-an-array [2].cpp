class Solution {
public:
    int xorOperation(int n, int start) {
        int ans=start; //ans=vec[0]=start+2*0=start
        for(int i=1; i<n; i++)
            ans=ans^(start+2*i);
        return ans;
    }
};