class Solution {
public:
    bool isUgly(int n) {
        if(n<=0) //num has to be +ive
            return false;
        while(n%2==0) // remove all 2 prime factors
            n=n/2;
        while(n%3==0) // remove all 3 prime factors
            n=n/3;
        while(n%5==0) // remove all 5 prime factors
            n=n/5;
        if(n==1)  // no prime factors except 2,3,5
            return true;
        return false;
    }
};