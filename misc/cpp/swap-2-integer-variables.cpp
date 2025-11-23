#include <bits/stdc++.h>
using namespace std;

// using a 3rd variable
void swap1(int& x, int& y){
    int temp = x; 
    x = y; 
    y = temp;
}

// without using a 3rd variable
// using addition and subtraction
// Disadvantage: can cause int-overflow for large values of x and y
void swap2(int& x, int& y){
    // let original values of variables x and y be x0 and y0
    // initially, x = x0, y = y0
    
    // x = x + y = x0 + y0
    x = x + y; 
    // y = x - y = (x0 + y0) - y0 = x0
    y = x - y; 
    // x = x - y = (x0 + y0) - x0 = y0
    x = x - y;
    
    // finally, x = y0, y = x0
}

// without using a 3rd variable
// using XOR
void swap3(int& x, int& y){
    // let original values of variables x and y be x0 and y0
    // initially, x = x0, y = y0
    
    // x = x ^ y = x0 ^ y0
    x = x ^ y; 
    // y = x ^ y = (x0 ^ y0) ^ y0 = x0 ^ (y0 ^ y0) = x0 ^ 0 = x0
    y = x ^ y; 
    // x = x ^ y = (x0 ^ y0) ^ x0 = (x0 ^ x0) ^ y0 = 0 ^ y0 = y0
    x = x ^ y;
    
    // finally, x = y0, y = x0
}
/*
properties of XOR used:
1. A ^ B = B ^ A ...[Commutative]
2. (A ^ B) ^ C = A ^ (B ^ C) ...[Associative]
3. A ^ 0 = A ...[Identity]
4. A ^ A = 0 ...[Negation]
*/

int main(){
    int x = 5, y = 7;
    
    cout<<"Before swap: ";
    cout<<"x = "<<x<<", y = "<<y<<endl;
    
    // Method 1
    // swap1(x, y);
    
    // Method 2
    // swap2(x, y);
    
    // Method 3
    swap3(x, y);
    
    // Method 4 (inbuilt)
    // swap(x, y);
    
    cout<<"After swap: ";
    cout<<"x = "<<x<<", y = "<<y<<endl;
    
    cout<<endl<<string(25, '-')<<endl;
    
    return 0;
}