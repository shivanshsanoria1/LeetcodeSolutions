class Solution {
public:
    int xorOperation(int n, int start) {
        int ans=start;
        n--;
        while(n>0)
        {
            start+=2;
            ans=ans^start;
            n--;
        }
        return ans;
    }
};