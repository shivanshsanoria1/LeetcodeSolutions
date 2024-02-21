class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.length(), zeros=0, ones=0, flips, min_flips=n;
        for(int i=0; i<n; i++) // count total no. of 0's and 1's
        {
            if(s[i]=='0')
                zeros++;
            else
                ones++;
        }
        if(zeros==n || ones==n) // string has only 0's or 1's
            return 0;
        int left_ones=0, right_zeros=0, left_zeros=0;
        for(int i=0; i<n; i++) // no. of flips will be the sum of (no. of 1's in left subarray) and (no. of 0's in right subarray)
        {
            if(s[i]=='1')
                left_ones++;
            else
                left_zeros++;
            right_zeros = zeros-left_zeros;
            flips = left_ones + right_zeros;
            if(flips < min_flips)
                min_flips=flips;
        }
        
        left_ones=0, right_zeros=zeros; // left subarray has size 0 
        flips = left_ones + right_zeros;
        if(flips < min_flips)
            min_flips=flips;
        
        left_ones=ones, right_zeros=0; // right subarray has size 0
        flips = left_ones + right_zeros;
        if(flips < min_flips)
            min_flips=flips;
        
        return min_flips;
    }
};