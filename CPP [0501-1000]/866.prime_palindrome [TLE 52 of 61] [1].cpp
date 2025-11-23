class Solution {
private:
    bool isPalindrome(int n){
        string s1 = to_string(n);
        string s2 = s1;
        reverse(s2.begin(), s2.end());

        return s1 == s2;
    }
    
    bool isPrime(int n){
        if(n == 1)
            return false;
        if(n == 2)
            return true;
        
        for(int i=3; i*i<=n; i+=2)
            if(n % i == 0)
                return false;
        
        return true;
    }

public:
    int primePalindrome(int n) {
        if(n <= 2)
            return 2;

        // if n is even, convert it to the next odd num
        if(n % 2 == 0)
            n++;
        
        while(!(isPalindrome(n) && isPrime(n)))
            n += 2;

        return n;
    }
};