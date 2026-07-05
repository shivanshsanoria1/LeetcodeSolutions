class Solution {
private:
    bool isPrime(const int num){
        if(num <= 1)
            return false;
        if(num == 2)
            return true;
        if(num % 2 == 0)
            return false;

        for(int i=3; i*i<=num; i += 2)
            if(num % i == 0)
                return false;
        
        return true;
    }

public:
    // T.C.=O(n*sqrt(n)), S.C.=O(1)
    int sumOfPrimesInRange(int n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        const int r = stoi(s);

        int sum = 0;
        for(int num = min(n, r); num <= max(n, r); num++)
            if(isPrime(num))
                sum += num;

        return sum;
    }
};