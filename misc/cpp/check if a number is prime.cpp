#include <bits/stdc++.h>
using namespace std;

// T.C.=O(sqrt(num))
bool isPrime(int num){
    // 0 and 1 are not prime
    if(num <= 1)
        return false;
    
    // 2 is prime
    if(num == 2)
        return true;
    
    // any even num > 2 is not prime
    if(num % 2 == 0)
        return false;
    
    // check divisibility by odd nums in range [3, sqrt(num)]
    for(int i=3; i*i <= num; i += 2)
        if(num % i == 0)
            return false;
    
    return true;
}

int main() {
    vector<int> nums = { 1, 2, 3, 16, 19, 77, 71, 13 };
    
    for(int num: nums)
    {
        cout<<num;
        if(isPrime(num))
            cout<<" is prime"<<endl;
        else
            cout<<" is not prime"<<endl;
    }
    
    cout<<endl<<string(25, '-')<<endl;

    return 0;
}