class Solution {
public:
    long long smallestNumber(long long num) {
        bool isNeg = num < 0 ? true : false;
        num = abs(num);

        vector<int> freq(10, 0);
        while(num > 0)
        {
            freq[num % 10]++;
            num /= 10;
        }
        
        long long int ans = 0;
        if(isNeg)
        {
            for(int i=9; i>=0; i--)
                while(freq[i]--)
                    ans = 10*ans + i;
        }
        else
        {
            for(int i=1; i<=9; i++)
                if(freq[i] > 0)
                {
                    ans = i;
                    freq[i]--;
                    break;
                }

            for(int i=0; i<=9; i++)
                while(freq[i]--)
                    ans = 10*ans + i;
        }

        return isNeg ? -ans : ans;
    }
};