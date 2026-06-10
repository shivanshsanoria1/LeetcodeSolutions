class Solution {
public:
    // T.C.=O(1), S.C.=O(1)
    // Math
    int maximumScore(int a, int b, int c) {
        // make sure a, b, c follow: a <= b <= c
        if(a > b)
            swap(a, b);
        if(b > c)
            swap(b, c);
        if(a > b)
            swap(a, b);
        
        return a + b <= c ? a + b : c + (a + b - c)/2;
    }
};