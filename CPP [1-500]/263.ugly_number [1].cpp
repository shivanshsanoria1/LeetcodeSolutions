class Solution {
public:
    // T.C.=O(log2(n) + log3(n) + log5(n)), S.C.=O(1)
    bool isUgly(int n) {
        // num has to be +ive
        if(n <= 0) 
            return false;
       
        // remove all 2's
        while(n % 2 == 0) 
            n /= 2;
        // remove all 3's
        while(n % 3 == 0) 
            n /= 3;
        // remove all 5's
        while(n % 5 == 0) 
            n /= 5;
        
        return n == 1;
    }
};