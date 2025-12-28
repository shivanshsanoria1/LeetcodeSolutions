vector<int> Solution::solve(vector<int> &A) {
    int n=A.size(), left=0, right=n-1, k=n-1;
    vector<int> ans(n);
    while(left<=right)
    {
        if(abs(A[left]) >= abs(A[right]))
        {
            ans[k] = A[left]*A[left];
            left++;
        }
        else
        {
            ans[k] = A[right]*A[right];
            right--;
        }
        k--;
    }
    return ans;
}
