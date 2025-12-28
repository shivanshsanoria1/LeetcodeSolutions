int Solution::addNumbers(int a, int b) {
    while(b != 0) //until there is no caryy left
    {
        int carry= a&b;
        a= a^b;
        b= carry<<1;
    }
    return a;
}
