// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left=1, right=n, mid;
        while(left<right)
        {
            mid=left+(right-left)/2;
            if(isBadVersion(mid) == false)
                left=mid+1;
            else
                right=mid;
        }
        return right; // at this point left=right so any one of them can be returned
    }
};