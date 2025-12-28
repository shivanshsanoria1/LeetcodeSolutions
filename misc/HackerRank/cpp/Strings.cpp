#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    string a = "", b= "";
    cin>>a;
    cin>>b;
    
    cout<<a.length()<<" "<<b.length()<<endl;
    cout<< a + b <<endl;
    
    swap(a[0], b[0]);
    
    cout<<a<<" "<<b<<endl;
     
    return 0;
}
