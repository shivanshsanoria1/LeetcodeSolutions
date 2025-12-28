int Solution::solve(vector<int> &a, int b, int c) {
    int even_count=0, odd_count=0;
    for(int i=0; i<a.size(); i++)
    {
        if(a[i]%2==0)
            even_count++;
        else
            odd_count++;
    }
    return b%2==0 ? odd_count*c : even_count*c; //if b is even then odd count are fined and vice versa
}
