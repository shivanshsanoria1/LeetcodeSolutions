class Solution {
private:
    typedef long long int lli;

    lli getFactorialZeros(lli num) {
        lli count = 0;
        lli pow5 = 5;

        while(pow5 <= num)
        {
            count += num / pow5;
            pow5 *= 5;
        }

        return count;
    }

public:
    int preimageSizeFZF(int k) {
        lli left = 0;
        lli right = LLONG_MAX;

        while(left <= right)
        {
            lli mid = left + (right - left) / 2;
            lli zerosCount = getFactorialZeros(mid);

            if(zerosCount == k)
                return 5;
            else if(zerosCount < k)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return 0;
    } 
};
// there are exactly 5 numbers whose factorial 
// has k trailing zeros, if possible