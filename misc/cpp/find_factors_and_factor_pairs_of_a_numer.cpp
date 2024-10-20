#include <bits/stdc++.h>
using namespace std;

// T.C.=O(sqrt(n))
vector<int> findFactors(int num){
    vector<int> factors1;
    vector<int> factors2;
    
    for(int i=1; i*i <= num; i++)
        if(num % i == 0)
        {
            factors1.push_back(i);
            if(i != num/i)
                factors2.push_back(num/i);
        }
    
    // append the reverse of factors2[] to the end of factors1[]
    factors1.insert(factors1.end(), factors2.rbegin(), factors2.rend());
    
    return factors1;
}

// T.C.=O(sqrt(n))
vector<pair<int, int>> findFactorPairs(int num){
    vector<pair<int, int>> factorPairs;
    
    for(int i=1; i*i <= num; i++)
        if(num % i == 0)
            factorPairs.push_back({i, num/i});
    
    return factorPairs;
}

int main() {
    int num = 36;
    
    vector<int> factors = findFactors(num);
    
    cout<<"Factors of "<<num<<" are: "<<endl;
    for(int factor: factors)
        cout<<factor<<" ";
    cout<<endl<<endl;
    
    vector<pair<int, int>> factorPairs = findFactorPairs(num);
    
    cout<<"Factors-pairs of "<<num<<" are: "<<endl;
    for(auto [f1, f2]: factorPairs)
        cout<<"("<<f1<<", "<<f2<<"), ";
    cout<<endl;
    
    cout<<endl<<string(25, '-')<<endl;

    return 0;
}