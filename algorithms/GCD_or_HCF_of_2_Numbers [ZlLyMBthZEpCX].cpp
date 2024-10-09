#include <bits/stdc++.h>
using namespace std;

// T.C.=O(sqrt(min(a, b)))
// Factorization method
int gcd1(int a, int b){
    int minVal = min(a, b);
    int maxVal = max(a, b);
    int gcdVal = 1;
    
    for(int f1=1; f1*f1 <= minVal; f1++)
    {
        if(minVal % f1 != 0)
            continue;
            
        int f2 = minVal / f1;
        
        if(maxVal % f1 == 0)
            gcdVal = max(gcdVal, f1);
        if(maxVal % f2 == 0)
            gcdVal = max(gcdVal, f2);
    }
    
    return gcdVal;
}

// T.C.=O(min(a, b))
// Euclidean algorithm by subtraction (Iterative)
int gcd2(int a, int b){
    while(a != b)
    {
        if(a > b)
            a -= b;
        else
            b -= a;
    }
    
    return a;
}

// T.C.=O(min(a, b))
// Euclidean algorithm by subtraction (Recursive)
int gcd3(int a, int b){
    if(a == 0)
        return b;
    if(b == 0)
        return a;
    
    if(a == b)
        return a;
    
    return a > b ? gcd3(a - b, b) : gcd3(a, b - a);
}

// T.C.=O(log(min(a, b)))
// Euclidean algorithm by modulo (Iterative)
int gcd4(int a, int b){
    while(a > 0 && b > 0)
    {
        if(a > b)
            a %= b;
        else
            b %= a;
    }
    
    return a == 0 ? b : a;
}

// T.C.=O(log(min(a, b)))
// Euclidean algorithm by modulo (Recursive)
int gcd5(int a, int b){
    if(a == 0)
        return b;
    if(b == 0)
        return a;
    
    return a > b ? gcd5(a % b, b) : gcd5(a, b % a);
}

int main() {
    int a = 30, b = 45;
    
    int gcd_val = gcd1(a, b);
    // int gcd_val = gcd2(a, b);
    // int gcd_val = gcd3(a, b);
    // int gcd_val = gcd4(a, b);
    // int gcd_val = gcd5(a, b);
    
    // inbuit; defined in 'algorithm' library; T.C.=O(log(min(a, b)))
    // int gcd_val = __gcd(a, b);
    
    // inbuit; defined in 'numeric' library; T.C.=O(log(min(a, b)))
    // int gcd_val = gcd(a, b); 
    
    cout<<"GCD of "<<a<<" and "<<b<<" = "<<gcd_val;

    cout<<endl<<"------------------------"<<endl;
    return 0;
}

// GCD: Greatest Common Divisor 
// HCF: Highest Common Factor