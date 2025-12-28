/*
 * Complete the 'minimumNumber' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING password
 */

int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    int sum, flag1=1, flag2=1, flag3=1, flag4=1;
    for(int i=0; i<n; i++)
    {
        if(password[i]>='0' && password[i]<='9')
        {
            if(flag1==1)
                flag1=0;
        }
        else if(password[i]>='a' && password[i]<='z')
        {
            if(flag2==1)
                flag2=0;
        }
        else if(password[i]>='A' && password[i]<='Z')
        {
            if(flag3==1)
                flag3=0;
        }
        else
        {
            if(flag4==1)
                flag4=0;
        }
    }
    sum=flag1+flag2+flag3+flag4;
    sum=max(sum,6-n);
    return sum;
}