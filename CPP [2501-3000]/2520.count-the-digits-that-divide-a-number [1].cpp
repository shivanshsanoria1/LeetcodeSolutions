class Solution {
public:
    int countDigits(int num) {
        vector<int> digitFreq(10, 0);
        int n = num;
        while(n > 0)
        {
            digitFreq[n % 10]++;
            n /= 10;
        }
        int ans = 0;
        for(int i=1; i<=9; i++)
            if(num % i == 0)
                ans += digitFreq[i];
        return ans;
    }
};