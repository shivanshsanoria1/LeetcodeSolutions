class Solution {
public:
    // T.C.=O(), S.C.=O(1)
    // Math soln.
    int minSteps(int n) {
        int ops = 0;
        int num = n;
        
        for(int i=2; i<=n && num > 1; i++)
            while(num % i == 0)
            {
                ops += i;
                num /= i;
            }
        
        return ops;
    }
};
/*
# just find the sum of prime factors of n
# each prime factor p of n corresponds to p operations:
  1 copy and (p-1) paste operations
# thus, the total num of operations is the 
  sum of all prime factors of n
*/
