class Solution {
public:
    int findComplement(int num) {
        int num_of_bits= floor(log2(num)) + 1;
        int max_value= pow(2,num_of_bits) - 1;
        return max_value - num;
    }
};