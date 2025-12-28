/*
 * Complete the 'diagonalDifference' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

int diagonalDifference(vector<vector<int>> arr) {
    int n=arr.size(), sum_left=0, sum_right=0;;
    for(int i=0; i<n; i++)
        sum_left+=+arr[i][i];
    for(int i=0; i<n; i++)
        sum_right+=+arr[i][n-1-i];
    return abs(sum_left-sum_right);
}