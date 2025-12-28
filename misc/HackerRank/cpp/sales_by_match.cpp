/*
 * Complete the 'sockMerchant' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY ar
 */

int sockMerchant(int n, vector<int> ar) { // 1<=ar[i]<=100
    vector<int> count(100,0); // vector of size 100 initialized by 0's
    int c=0;
    for(int i=0; i<ar.size(); i++)
        count[ar[i]-1]++;
    for(int i=0; i<100; i++)
        c = c+count[i]/2;
    return c;
}
