int Solution::solve(string a, string b) {
    int len1=a.length(), len2=b.length();
    int base= a[len1-1]-'0'; //last digit of a
    if(base==0 || base==1 || base==5 || base==6) //last digit of a is 0, 1, 5, 6
        return base;
    int expo= b[len2-1]-'0'; //last digit of b
    if(len2 > 1) //2nd last digit of b exists
        expo+= 10*(b[len2-2]-'0'); //formed by last 2 digs of b (we only need last 2 digs of b as we are reducing b mod 4)
    if(expo%4==0)
        expo=4;
    else
        expo=expo%4;
    int ans= pow(base,expo);
    return ans%10;
}
//last digit for x^y is periodic, with max period of 4
//last digit of x - last digit of x^y, y=1,2,3,4,... (since y is very large we reduce y mod 4)
//              0 - 0
//              1 - 1
//              2 - 2,4,8,6
//              3 - 3,9,7,1
//              4 - 4,6
//              5 - 5
//              6 - 6
//              7 - 7,9,3,1
//              8 - 8,4,2,6
//              9 - 9,1