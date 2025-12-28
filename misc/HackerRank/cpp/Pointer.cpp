#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void update(int *a,int *b) {
    // Complete this function 
    
    int tempA = *a;
    int tempB = *b;
    
    *a = tempA + tempB;
    *b = abs(tempA - tempB);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  

    int a, b;
    cin>>a>>b;
    
    int *ptrA = &a;
    int *ptrB = &b;
    
    update(ptrA, ptrB);
    
    cout<<a<<endl;
    cout<<b<<endl;
    
    return 0;
}
