/*
 * Complete the 'findDigits' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER n as parameter.
 */

int findDigits(int n) {
    int num=n, c=0;
    while(num>0)
    {
        int d=num%10;
        if(d!=0 && n%d==0)
            c++;
        num=num/10;
    }
    return c;
}