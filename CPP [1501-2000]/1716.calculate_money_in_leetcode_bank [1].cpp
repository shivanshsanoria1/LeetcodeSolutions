class Solution {
public:
    int totalMoney(int n) { // T.C.=O(1), S.C.=O(1)
        int weeks = n/7, remainingDays = n % 7; 
        int weekSum = 28*weeks + 7*((weeks - 1)*weeks)/2; 
        int remainingDaysSum = (weeks + 1)*remainingDays + ((remainingDays - 1)*remainingDays)/2; 
        return weekSum + remainingDaysSum;
    }
};
/*
# weeks: num of complete weeks
# remainingDays: days in the last incomplete week
# formula for the sum of A.P. with first term 'a', differnce 'd' and 'n' terms is
  Sn = (n/2)(2*a + (n-1)*d)
# Eg-
n - mon tue wed thu fri sat sun - sum
1 - 1   2   3   4   5   6   7   - 28
2 - 2   3   4   5   6   7   8   - 28 + 1*7
3 - 3   4   5   6   7   8   9   - 28 + 2*7
4 - 4   5   6   7   8   9   10  - 28 + 3*7
5 - 5   6   7   ...

weeks: num of fully filled rows = 4
remainingDays: num of cols in the last incomplete row = 3
weekSum: sum of all fully filled rows 
= (weeks/2) * ((2*28) + (weeks-1)*7)
= 28*weeks + 7*((weeks)*(weeks-1))/2
= 28*4 + 7*(4*3)/2 = 112 + 42 = 154
remainingDaysSum: sum of the last incomplete row (a = row + 1, d = 1)
= (remainingDays/2) * (2*(weeks + 1) + (remainingDays-1)*1)
= remainingDays * (weeks + 1) + (remainingDays*(remainingDays - 1))/2
= 3*5 + (3*2)/2 = 18
*/