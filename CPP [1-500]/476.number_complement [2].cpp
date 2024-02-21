class Solution {
public:
    int findComplement(int num) {
        int num_of_bits= floor(log2(num)) + 1; //find number of bits in the given num
        int mask= pow(2,num_of_bits) - 1; //generate a number with number of set bits equal to the number of bits in the given num
        return mask ^ num;
    }
};