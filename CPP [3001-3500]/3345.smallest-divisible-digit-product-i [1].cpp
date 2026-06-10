class Solution {
private:
    int productOfDigits(int num){
        int prod = 1;
        while(num > 0)
        {
            prod *= num % 10;
            num /= 10;
        }

        return prod;
    }

public:
    // T.C.=O(t), S.C.=O(1)
    int smallestNumber(int n, int t) {
        while(productOfDigits(n) % t != 0)
            n++;
        
        return n;
    }
};