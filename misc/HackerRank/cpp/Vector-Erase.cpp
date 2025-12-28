#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int n;
    cin>>n;
    
    vector<int> vec(n);
    for(int i=0; i<n; i++)
        cin>>vec[i];
    
    int x;
    cin>>x;
    
    int a, b;
    cin>>a>>b;
    
    // -1 is done to convert 1-based index into 0-based
    x--;
    a--;
    b--;
    
    vec.erase(vec.begin() + x);
    vec.erase(vec.begin() + a, vec.begin() + b);
    
    cout<<vec.size()<<endl;
    
    for(int num: vec)
        cout<<num<<" ";
    
    return 0;
}
