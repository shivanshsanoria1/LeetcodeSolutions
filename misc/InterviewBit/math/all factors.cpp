vector<int> Solution::allFactors(int n) {
    vector<int> factors;
    for(int i=1; i*i<=n; i++) // find factors upto sqrt(n) (including sqrt(n))
        if(n%i==0)
            factors.push_back(i);
    vector<int> factors2;
    for(int i=factors.size()-1; i>=0; i--) // find the other member of each factor corresponding to the factor pair
        if(factors[i]*factors[i]!=n) // sqrt(n) does not have any factor pair
            factors2.push_back(n/factors[i]);
    for(int i=0; i<factors2.size(); i++)
        factors.push_back(factors2[i]);
    return factors;
}
