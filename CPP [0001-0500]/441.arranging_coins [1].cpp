class Solution {
public:
    int arrangeCoins(int n) {
        int num=1;
        long int sum=1;
        while(sum < n)
        {
            num++;
            sum+=num;
        }
        return sum==n ? num : num-1;
    }
};