#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Rectangle{
protected:
    int width;
    int height;
    
public:
    void display() {
        cout<<width<<" "<<height<<endl;
    }
};

class RectangleArea: public Rectangle{
public:  
    void read_input(){
        cin>>width>>height;
    }
    
    void display() {
        cout<<width * height<<endl;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    RectangleArea ra1;
    
    ra1.read_input();
    
    ra1.Rectangle::display();
    ra1.display();
     
    return 0;
}
