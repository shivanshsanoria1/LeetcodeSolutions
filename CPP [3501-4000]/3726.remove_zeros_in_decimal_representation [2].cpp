class Solution {
public:
    long long removeZeros(long long n) {
        long long int ans = 0;
        for(long long int m=1; n > 0; n /= 10){
            int dig = n % 10;
            if(dig == 0)
                continue;

            ans += m*dig;
            m *= 10;
        }

        return ans;
    }
};