class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int count = 0;
        for(int a=1; a<=n; a++)
        {
            long long int k = 2*n + (long long int)a*(a-1);
            double d = sqrt(1 + 4*k);
            if(floor(d) == ceil(d) && (-1 + (int)d) % 2 == 0)
                count++;
        }
        return count;
    }
};
/*
# let original num be N
# suppose S(x, y): sum of all natural nums in range [x, y] (both inclusive)
# N = S(a, b)
  N = S(1, b) - S(1, a-1)
  N = (1/2) * (b*(b+1) - (a-1)*a)
  b*(b+1) = 2*N + a*(a-1)
  b*(b+1) = K       ; (let K = 2*N + a*(a-1))
  b^2 + b - K = 0
  b = (-1 + sqrt(1 + 4*K)) / 2
# -ive sign is excluded in quadratic formula since b > 0
# since b is a natural number, 
  (1 + 4*K) must be a perfect square and
  (-1 + sqrt(1 + 4*K)) must be even
*/