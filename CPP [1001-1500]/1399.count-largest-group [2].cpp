class Solution {
public:
    int digitSum(int n)
    {
        int sum=0;
        while(n>0)
        {
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
        
    int countLargestGroup(int n) { //max value of n is 10000, so max digit sum will be 36 (for the num 9999), so size of vector is taken 37
        vector<int> freq(37,0); //ith index represents digit sum=i and element at ith index represents freq
        int max_freq=0, c=0;
        for(int i=1; i<=n; i++)
        {
            int curr_digit_sum= digitSum(i);
            freq[curr_digit_sum]++;
            if(freq[curr_digit_sum] > max_freq)
            {
                max_freq= freq[curr_digit_sum];
                c=1;
            }
            else if(freq[curr_digit_sum] == max_freq)
                c++;
        }
        return c;
    }
};