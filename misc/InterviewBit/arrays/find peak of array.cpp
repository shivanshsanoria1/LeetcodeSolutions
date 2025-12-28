int Solution::perfectPeak(vector<int> &A) {
    int n=A.size(), left_max=A[0], right_min=A[n-1];
    vector<bool> left(n,false), right(n,false);
    for(int i=1; i<n; i++)
    {
        if(A[i]>left_max)
        {
            left[i]=true;
            left_max=A[i];
        }
    }
    for(int i=n-2; i>=0; i--)
    {
        if(A[i]<right_min)
        {
            right[i]=true;
            right_min=A[i];
        }
    }
    for(int i=0; i<n; i++)
        if(left[i]==true && right[i]==true)
            return 1;
    return 0;
}
