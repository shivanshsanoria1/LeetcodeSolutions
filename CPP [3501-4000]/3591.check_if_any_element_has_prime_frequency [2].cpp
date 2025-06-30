class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        vector<int> freq(101, 0);
        for(int num: nums)
            freq[num]++;
        
        // primes upto 100
        vector<int> primes = 
        {
            2,3,5,7,
            11,13,17,19,
            23,29,
            31,37,
            41,43,47,
            53,59,
            61,67,
            71,73,79,
            83,89,
            97
        };
        
        for(int i=0; i<=100; i++)
            for(int prime: primes)
                if(freq[i] == prime)
                    return true;

        return false;
    }
};