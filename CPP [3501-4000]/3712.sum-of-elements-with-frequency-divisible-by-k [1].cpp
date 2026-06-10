class Solution {
public:
    // T.C.=(n + 100), S.C.=(100)
    int sumDivisibleByK(vector<int>& nums, int k) {
        vector<int> freq(101, 0);
        for(int num: nums)
            freq[num]++;
        
        int sum = 0;
        for(int i=1; i<=100; i++)
            if(freq[i] > 0 && freq[i] % k == 0)
                sum += i*freq[i];

        return sum;
    }
};