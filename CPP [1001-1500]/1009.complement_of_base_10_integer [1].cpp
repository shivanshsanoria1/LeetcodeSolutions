class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)
            return 1;
        int num_of_bits= floor(log2(n)) + 1;
        int max_value= pow(2,num_of_bits) - 1;
        return max_value - n;
    }
};