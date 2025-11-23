class Solution {
public:
    int mySqrt(int x) {
        if(x==0)
            return 0;
        int left=1,right=x,mid;
        while(left<=right)
        {
            mid= left+(right-left)/2; // mid=(left+right)/2
            if(mid == x/mid) // mid^2 == x
                return mid;
            else if(mid < x/mid) // mid^2 < x
                left=mid+1;
            else if(mid > x/mid) // mid^2 > x
                right=mid-1;
        }
        return right;
    }
};