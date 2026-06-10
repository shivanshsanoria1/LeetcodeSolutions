class Solution {
private:
    int digitSum(int num){
        int sum = 0;
        while(num > 0)
        {
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }

    int digitProd(int num){
        int prod = 1;
        while(num > 0)
        {
            prod *= num % 10;
            num /= 10;
        }

        return prod;
    }

public:
    bool checkDivisibility(int n) {
        return n % (digitSum(n) + digitProd(n)) == 0;
    }
};