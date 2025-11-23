class Solution {
private:
    bool isUgly(int num) {
        // remove all 2's
        while(num % 2 == 0) 
            num /= 2;
        // remove all 3's
        while(num % 3 == 0) 
            num /= 3;
        // remove all 5's
        while(num % 5 == 0) 
            num /= 5;
        
        return num == 1;
    }

public:
    int nthUglyNumber(int n) {
        int x = 1;
        while(n > 0)
        {
            if(isUgly(x))
                n--;
            x++;
        }

        return x-1;
    }
};