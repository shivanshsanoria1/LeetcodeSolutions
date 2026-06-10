class Solution {
public:
    // T.C.=O(sqrt(n)), S.C.=O(1)
    bool checkPerfectNumber(int num) { 
        // 1 is not a perfect num
        if(num == 1) 
            return false;

        int sum = 0;
        for(int i=2; i*i <= num; i++)
            if(num % i == 0)
            {
                sum += i;
                // prevents the case of counting i twice when
                // num is a perfect square and i = sqrt(num)
                if(i != num/i)
                    sum += num/i;
            }

        return 1 + sum == num;
    }
};