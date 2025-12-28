int Solution::repeatedNumber(const vector<int> &A) { // T.C.=O(n) ; S.C.=O(n)
    int n=A.size();
    vector<int> check(n,0); // stores the freq. of elements in the range [1,n-1]
    for(int i=0; i<n; i++)
        check[A[i]]++;
    for(int i=1; i<n; i++)
        if(check[i]>=2) // freq.>=2 means element is repeated 
            return i;
    return -1; // no repeated element found
}
