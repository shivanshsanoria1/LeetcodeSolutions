#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int max_of_four(int a, int b, int c, int d){
    return max(max(a, b), max(c, d));
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    
    cout<<max_of_four(a, b, c, d);
    
    return 0;
}
