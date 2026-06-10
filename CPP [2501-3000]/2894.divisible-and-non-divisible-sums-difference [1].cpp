class Solution {
public:
    // T.C.=O(n), S.C.=O(1)
    int differenceOfSums(int n, int m) {
        int num2 = 0;
        for(int i=1; i<=n; i++)
            if(i % m == 0)
                num2 += i;
        return (n*(n+1))/2 - 2*num2;
    }
};
/*
# sum of all nums from 1 to n = (n*(n+1))/2
# sum of nums from 1 to n that are divisible by m = num2
# sum of nums from 1 to n that are not divisible by m = num1
  = (n*(n+1))/2 - num2
# num1 - num2 
  = (n*(n+1))/2 - num2 - num2 
  = (n*(n+1))/2 - 2*num2
*/