vector<int> Solution::maxset(vector<int> &A) {
    int n=A.size();
    long long int sum=0, max_sum=0;
    vector<int> sub, max_sub;
    for(int i=0; i<n; i++)
    {
        if(A[i]>=0)
        {
            sum=sum+A[i];
            sub.push_back(A[i]);
            if(sum > max_sum)
            {
                max_sum=sum;
                max_sub=sub;
            }
            else if(sum == max_sum && sub.size() > max_sub.size())
            {
                max_sub=sub;
            }
        }
        else
        {
            sum=0;
            sub.clear();
        }
    }
    return max_sub;
}
