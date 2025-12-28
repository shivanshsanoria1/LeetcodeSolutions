int Solution::solve(vector<int> &A) {
    int min=INT_MAX, max=INT_MIN, n=A.size();
    for(int i=0; i<n; i++)
    {
        if(A[i] < min)
            min=A[i];
        if(A[i] > max)
            max=A[i];
    }
    return max+min;
}
