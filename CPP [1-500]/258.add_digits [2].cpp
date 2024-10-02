class Solution {
public:
    // T.C.=O(1), S.C.=O(1)
    // Math
    int addDigits(int num) {
        if(num == 0)
            return 0;

        return num % 9 == 0 ? 9 : num % 9;
    }
};

// just calculate the digital-root of the num