int Solution::solve(int y) {
    if(y%400==0) //divisible by 400
        return true;
    else if (y%100==0) //not divisible by 400 but divisible by 100
        return false;
    else if(y%4==0) //not divisible by 100 but divisible by 4
        return true;
    return false;
}
