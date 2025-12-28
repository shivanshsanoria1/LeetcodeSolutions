int Solution::solve(int n) {
    int dig_sum=0;
    do{
        while(n > 0)
        {
            dig_sum+= n%10;
            n/=10;
        }
        n=dig_sum; //store digit sum in n
        dig_sum=0; //reset digit sum
    }while(n > 9); //until curr digit sum becomes 1 digit
    return n;
}