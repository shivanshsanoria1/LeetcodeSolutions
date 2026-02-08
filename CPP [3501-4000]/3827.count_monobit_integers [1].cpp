class Solution {
public:
    // T.C.=O(log(n)), S.C.=O(1)
    // Math
    int countMonobit(int n) {
        return 1 + floor(log2(n+1));
    }
};

// every monobit int is of the form (2^n - 1), n=0,1,2,...