/*
 * Complete the 'staircase' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void staircase(int n) {
    for(int i=1; i<=n; i++)
    {
        for(int j=n-i; j>0; j--)
            cout << " ";
        for(int j=1; j<=i; j++)
            cout << "#";
        cout << endl;
    }
}