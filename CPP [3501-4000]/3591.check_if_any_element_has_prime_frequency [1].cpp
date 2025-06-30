class Solution {
private:
    bool isPrime(int num){
        if(num <= 1)
            return false;
        if(num == 2)
            return true;
        if(num % 2 == 0)
            return false;

        for(int i=3; i*i<=num; i+=2)
            if(num % i == 0)
                return false;
        
        return true;
    }

public:
    bool checkPrimeFrequency(vector<int>& nums) {
        vector<int> freq(101, 0);
        for(int num: nums)
            freq[num]++;
        
        for(int i=0; i<=100; i++)
            if(isPrime(freq[i]))
                return true;

        return false;
    }
};