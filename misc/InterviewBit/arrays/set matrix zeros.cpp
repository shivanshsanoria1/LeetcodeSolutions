void Solution::setZeroes(vector<vector<int> > &A) {
    int r=A.size(), c=A[0].size();
    vector<bool> row(r,false), col(c,false);
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            if(A[i][j]==0)
            {
                row[i]=true;
                col[j]=true;
            }
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            if(row[i] || col[j])
                A[i][j]=0;
}
