#include <bits/stdc++.h>
using namespace std;

vector<int> findPrimeFactors(int num){
    vector<int> primeFactors;
    
    while(num % 2 == 0)
    {
        primeFactors.push_back(2);
        num /= 2;
    }
    
    for(int i=3; i*i <= num; i += 2)
        while(num % i == 0)
        {
            primeFactors.push_back(i);
            num /= i;
        }
    
    // handle the case where num is a prime num > 2
    if(num > 2)
        primeFactors.push_back(num);
    
    return primeFactors;
}

vector<pair<int, int>> findPrimeFactorsWithExponents(int num){
    vector<pair<int, int>> primeFactors;
    
    int expo = 0;
    while(num % 2 == 0)
    {
        expo++;
        num /= 2;
    }
    if(expo > 0)
        primeFactors.push_back({2, expo});
    
    for(int i=3; i*i <= num; i += 2)
    {
        int expo = 0;
        while(num % i == 0)
        {
            expo++;
            num /= i;
        }
        if(expo > 0)
            primeFactors.push_back({i, expo});
    }
    
    // handle the case where num is a prime num > 2
    if(num > 2)
        primeFactors.push_back({num, 1});
    
    return primeFactors;
}

int main() {
    int num = 2520;
    
    vector<int> primeFactors = findPrimeFactors(num);
    
    cout<<"Prime-Factorization of "<<num<<" is: "<<endl;
    for(int p: primeFactors)
        cout<<p<<" ";
    cout<<endl<<endl;
    
    vector<pair<int, int>> primeFactorsWithexpoonents = findPrimeFactorsWithExponents(num);
    
    cout<<"Prime-Factorization of "<<num<<" (in Exponent form) is: "<<endl;
    for(auto [p, expo]: primeFactorsWithexpoonents)
        cout<<p<<"^"<<expo<<", ";
    cout<<endl;
    
    cout<<endl<<string(25, '-')<<endl;

    return 0;
}