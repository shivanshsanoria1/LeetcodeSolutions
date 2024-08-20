class Solution {
public:
    // T.C.=O(), S.C.=O(1)
    // Math soln.
    int minSteps(int n) {
        int ops = 0;
        int num = n;

        for(int f=2; f*f <= n; f++)
            while(num % f == 0)
            {
                ops += f;
                num /= f;
            }

        // n is a prime itself
        return num > 1 ? ops + num : ops;
    }
};
/*
# just find the sum of prime factors of n
# each prime factor p of n corresponds to p operations:
  1 copy and (p-1) paste operations
# thus, the total num of operations is the 
  sum of all prime factors of n
*/
