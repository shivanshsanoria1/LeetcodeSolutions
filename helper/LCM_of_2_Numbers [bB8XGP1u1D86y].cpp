#include <bits/stdc++.h>
using namespace std;

// T.C.=O(min(a, b))
int lcm1(int a, int b){
    int maxVal = max(a, b);
    int minVal = min(a, b);
    
    for(int m=1; m <= minVal; m++)
        if((maxVal * m) % minVal == 0)
            return maxVal * m;
    
    return -1;
}

int main() {
    int a = 30, b = 45;
    
    int lcm_val = lcm1(a, b);
    
    // using inbuilt gcd() 
    // int lcm_val = (a*b) / gcd(a, b);
    
    cout<<"LCM of "<<a<<" and "<<b<<" = "<<lcm_val;

    cout<<endl<<"------------------------"<<endl;
    return 0;
}

// LCM: Lowest Common Multiple
// formula used: a * b = gcd(a, b) * lcm(a, b)