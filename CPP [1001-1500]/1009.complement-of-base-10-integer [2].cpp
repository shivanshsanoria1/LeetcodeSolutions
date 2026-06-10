class Solution {
public:
    // Bit-manipulation
    int bitwiseComplement(int n) {
        if(n == 0)
            return 1;

         // find the min number of bits to represent the given num
        int bits = floor(log2(n)) + 1; 
        // generate a number with number of set bits equal 
        // to the number of bits in the given num
        int mask = (1 << bits) - 1; 

        return n ^ mask;
    }
};

/*
# pow(2, n) = (1 << n)
# Eg: 
  num = (5)10 = (101)2 and mask = (111)2
  num ^ mask = (101)2 ^ (111)2 = (010)2 = (2)10
# using the property of XOR: A ^ 1 = !A
# in general:
  num  = (A(n-1)  ...  A2  A1  A0)2
  mask = (1       ...  1   1   1 )2
  XOR
  ---------------------------------
       = (!A(n-1) ... !A2 !A1 !A0)2

# similar: [476. number-complement]
*/