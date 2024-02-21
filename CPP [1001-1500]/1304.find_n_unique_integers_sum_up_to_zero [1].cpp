class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n);
        int left, right, x=1;
        if(n%2==0) //even length array {...,-3,-2,-1,1,2,3,...}
        {
            right=n/2;
            left=n/2-1;
        }
        else //odd length array {...,-2,-1,0,1,2,...}
        {
            ans[n/2]=0;
            right=n/2+1;
            left=n/2-1;   
        }
        while(left>=0 && right<n)
        {
            ans[right]=x;
            ans[left]=-x;
            right++;
            left--;
            x++;
        }
        return ans;
    }
};