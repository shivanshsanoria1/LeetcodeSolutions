class Solution {
public:
    // T.C.=O(1), S.C.=O(1)
    // Math
    int minCost(int n) {
        return n*(n-1)/2;
    }
};

/*
# splitting any +ive num n into a,b such that n = a+b
# the prod a*b is max when a and b are as close as possible
  and min when a and b are as far away as possible
# so here the prod a*b is min when a=1, b=n-1
  a*b = 1*(n-1) = n-1
# next step is to split (n-1) in the same way to get (n-2)
# this process continues until the prod is 1
# thus total cost = (n-1) + (n-2) + ... + 1 = ((n-1)*n)/2
*/