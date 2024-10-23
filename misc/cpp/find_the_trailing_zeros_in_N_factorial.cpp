#include <bits/stdc++.h>
using namespace std;

// T.C.=O(log5(n)), S.C.=O(1)
int countFactorialTrailingZeros(int n){
    int mul = 5;
    int zeros = 0;
    
    while(n/mul > 0)
    {
        zeros += n/mul;
        mul *= 5;
    }
    
    return zeros;
}

int main() {
    int n = 28;
    
    cout<<"Number of trailing zeros in "<<n<<"! = "<<countFactorialTrailingZeros(n)<<endl;
    
    cout<<endl<<string(25, '-')<<endl;

    return 0;
}

/*
# the number of trailing 0's in n! is given by 
  summing the num of multiples of 5^1, 5^2, 5^3, ..., 5^x in n
  where 5^x <= n, ie, x <= log5(n)
# thus, trailing 0's in n! 
  = floor(n/5^1) + floor(n/5^2) + floor(n/5^3) + ... + floor(n/5^x)

# checkout: Leetcode [172. factorial-trailing-zeroes]
*/