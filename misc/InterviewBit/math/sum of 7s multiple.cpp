long Solution::solve(int a, int b) {
    long int n= (b-a+1)/7; //number of groups of 7
    int rem= (b-a+1)%7;
    int start=0;
    for(int i=a; i<a+7; i++) //find 1st multiple of 7
        if(i%7==0)
        {
            start=i;
            break;
        }
    for(int i=a; i<a+rem; i++) //check the first 'rem' numbers to see if there is a multiple of 7
        if(i%7==0)
        {
            n=n+1;
            break;
        }
    return (n*(2*start + 7*(n-1)))/2; //sum of AP
}
