class Solution {
private:
    bool isSpecial(int num){
        int properDivisors = 0;
        for(int i=1; i*i<=num; i++)
        {
            if(num % i != 0)
                continue;
            if(i != num)
                properDivisors++;
            if(i != num/i && num/i != num)
                properDivisors++;
            if(properDivisors > 2)
                break;
        }

        return properDivisors == 2;
    }

public:
    // T.C.=O(r-l), S.C.=O(1)
    int nonSpecialCount(int l, int r) {
        int specialCount = 0;
        for(int i=l; i<=r; i++)
            if(isSpecial(i))
                specialCount++;
        
        return (r-l+1) - specialCount;
    }
};
/*
# proper divisors: divisors of a num other than the num itself
# special num: a num which has exactly 2 proper divisors
*/