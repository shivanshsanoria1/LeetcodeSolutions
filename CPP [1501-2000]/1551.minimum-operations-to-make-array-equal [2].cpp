class Solution {
public:
    int minOperations(int n) {
        return n % 2 == 0 ? n*n/4 : (n-1)*(n+1)/4;
    }
};
/*
# initial array is of size n, filled with odd nums
# sum of the array
  = (n/2)*(2*a + (n-1)*d) 
  = (n/2)*(2*1 + (n-1)*2)
  = (n/2)*(2 + 2*n - 2)
  = (n/2)*(2*n)
  = n^2
# the sum of the array remains unchanged at any step
# in the final array all the n nums are equal and so each num must be n

# for n = 6,
# initial array: [1, 3, 5, 7, 9, 11]
# final array: [6, 6, 6, 6, 6, 6]
# diff = |1-6| + |3-6| + |5-6| + |7-6| + |9-6| + |11-6|
       = 5 + 3 + 1 + 1 + 3 + 5
       = 18
# ans = diff/2 = 18/2 = 9
# if n is even, ans = 1 + 3 + 5 + ... (n/2 times)
  = (1/2)*(n/2)*(2*1 + (n/2-1)*2)
  = (1/2)*(n/2)*(2 + n - 2)
  = (n^2)/4

# for n = 5, 
# initial array: [1, 3, 5, 7, 9]
# final array: [5, 5, 5, 5, 5]
# diff = |1-5| + |3-5| + |5-5| + |7-5| + |9-5|
       = 4 + 2 + 0 + 2 + 4
       = 12
# ans = diff/2 = 12/2 = 6
# if n is odd, ans = 2 + 4 + 6 + ... ((n-1)/2 times)
  = (1/2)*((n-1)/2)*(2*2 + ((n-1)/2 - 1)*2)
  = (1/2)*((n-1)/2)*(4 + (n-1) - 2)
  = (1/2)*((n-1)/2)*(n+1)
  = (n-1)*(n+1)/4
*/