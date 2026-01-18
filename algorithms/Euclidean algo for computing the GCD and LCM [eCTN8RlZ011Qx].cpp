#include <bits/stdc++.h>
using namespace std;

// recursive
// T.C.=O(log(min(a, b))), S.C.=O(log(min(a, b)))
int gcd1(int a, int b){
    return b == 0 ? a : gcd1(b, a % b);
}

// iterative
// T.C.=O(log(min(a, b))), S.C.=O(1)
int gcd2(int a, int b){
    while(b > 0){
        a %= b;
        swap(a, b);
    }
    
    return a;
}

// using the fact that:
// a*b = gcd(a, b) * lcm(a, b)
int lcm(int a, int b){
    return a / gcd2(a, b) * b;
}

int main() {
    int a = 18, b = 12;
    
    cout<<"GCD of "<<a<<" and "<<b<<" = "<<gcd1(a, b)<<endl;
    cout<<"GCD of "<<a<<" and "<<b<<" = "<<gcd2(a, b)<<endl;
    
    cout<<"LCM of "<<a<<" and "<<b<<" = "<<lcm(a, b)<<endl;

    return 0;
}