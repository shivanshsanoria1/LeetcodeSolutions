int Solution::firstMissingPositive(vector<int> &A) {
    int n=A.size(), min=1;
        sort(A.begin(),A.end());
        for(int i=0; i<n; i++)
        {
            if(A[i]>0)
            {
                if(A[i]==min)
                    min++;
                else if(A[i]>min)
                    return min;
            }
        }
        return min;
}
