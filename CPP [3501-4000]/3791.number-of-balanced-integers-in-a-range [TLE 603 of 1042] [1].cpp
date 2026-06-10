class Solution {
private:
    bool isBalanced(long long int num){
        long long int sum = 0;
        for(int sign = 1; num > 0; sign *= -1, num /= 10)
            sum += sign * (num % 10);

        return sum == 0;
    }

public:
    // T.C.=O(high - low), S.C.=O(1)
    long long countBalanced(long long low, long long high) {
        long long int count = 0;
        for(long long int i = max(low, 0LL); i <= high; i++)
            if(isBalanced(i))
                count++;

        return count;
    }
};